#include "dontedit.h"
#include "Header.h"
#include "run.h"

int indexUserLoged;
int countUser = 0;
void window() {
	SetConsoleTitle(L"Hello");
	SetWindowSize(200, 90);
	ShowScrollbar(0);
}
user userItem[30];
void readUserData() {
	int k = 0;
	ifstream infile;
	//cin.ignore();
	
	infile.open("user.txt", ios_base::in);
	while (infile.eof() != true) {
		getline(infile, userItem[k].ID, ',');
		string username, pass;
		getline(infile, username, ',');
		getline(infile, pass, ',');
		userItem[k].setUsername(username);
		userItem[k].setPassword(pass);
		getline(infile, userItem[k].email, ',');
		getline(infile, userItem[k].name, ',');
		getline(infile, userItem[k].gender, ',');
		getline(infile, userItem[k].pNum, ',');
		getline(infile, userItem[k].bdate, ',');
		getline(infile, userItem[k].address, ',');
		getline(infile, userItem[k].permiss, ',');
		getline(infile, userItem[k].position);
		k++;
		countUser = k;
	};
	infile.close();
}

bool processLogin(string user, string pass) {
	readUserData();
	for (int i = 0; i < countUser; i++) {
		if (userItem[i].getUsername() == user) {
			if (userItem[i].getPassword() == pass) {
				indexUserLoged = i;
				return true;
			}
		}
	}
	return false;
}

void loginMenu() {
	int ok = 1;
	do {
		gotoXY(50, 1);
		SetColor(11);
		for (int x = 50; x <= 90; x++) {
			gotoXY(x, 0);
			cout << char(196);
			gotoXY(x, 15);
			cout << char(196);
		}
		for (int y = 1; y <= 15; y++) {
			gotoXY(50, y);
			cout << char(179);
			gotoXY(90, y);
			cout << char(179);
		}
		gotoXY(50, 0); cout << char(218);
		gotoXY(90, 0); cout << char(191);
		gotoXY(90, 15); cout << char(217);
		gotoXY(50, 15); cout << char(192);


		gotoXY(63, 1); cout << char(175) << " DANG NHAP " << char(174);
		
		string userN="";
		string pass="";
		gotoXY(53, 3); cout << "Ten nguoi dung :";
		gotoXY(53, 5); cout << "Mat khau :";
		gotoXY(69, 3);  getline(cin, userN);
		gotoXY(63, 5);  getline(cin, pass);
		if (processLogin(userN, pass)) {
			system("cls");
			break;
		 ok = 0;
		}
		system("cls");
		SetColor(4); gotoXY(53, 7); cout << "Nhap sai ten nguoi dung/mat khau";
	} while (ok);
}


void startMenu() {
	int ok = 1;

	//vẽ khung
	gotoXY(50, 1);
	SetColor(11);
	for (int x = 50; x <= 90; x++) {
		gotoXY(x, 0);
		cout << char(196);
		gotoXY(x, 15);
		cout << char(196);
	}
	for (int y = 1; y <= 15; y++) {
		gotoXY(50, y);
		cout << char(179);
		gotoXY(90, y);
		cout << char(179);
	}
	gotoXY(50, 0); cout << char(218);
	gotoXY(90, 0); cout << char(191);
	gotoXY(90, 15); cout << char(217);
	gotoXY(50, 15); cout << char(192);
	//---kết thúc vẽ khung--//

	ListUser L1;
	do {

		gotoXY(64, 1); cout << char(175) << " CHUC NANG " << char(174);
		gotoXY(52, 2); cout << " 1" << char(175) << " Quan ly vat pham ";
		gotoXY(52, 3); cout << " 2" << char(175) << " Dat ban - dat ban truoc ";
		gotoXY(52, 4); cout << " 3" << char(175) << " Goi mon ";

		if (userItem[indexUserLoged].permiss == "manager") {
			gotoXY(52, 5); cout << " 5" << char(175) << " Quan ly nhan vien ";
			gotoXY(52, 6); cout << " 6" << char(175) << " Thong ke ";
		}
		gotoXY(52, 7); cout << " 0" << char(175) << " Dang xuat ";
		gotoXY(52, 9); cout <<" Chon chuc nang " << char(175) << " ";
		int choose;
		cin >> choose;
		switch(choose) {
		case 1: {
			 manageFood();
			
			break;
		}
		case 2: {
			 //bookTable();
			break;
		}
		case 3: {
			// order();
			break;
		}
		case 4: {
			// manageStaff();
			break;
		}
		case 5: {
			// analyst();
			break;
		}
		case 0:{
			ok = 0;
			break;
			  }
		}
	} while (ok);
}


int run() {
	window();
	loginMenu();//kiểm tra thử đăng nhập có ok hay k
	startMenu();
	cout << "pass";

	return 0;
}