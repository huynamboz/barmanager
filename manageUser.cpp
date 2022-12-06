#include "dontedit.h"
#include "Header.h"


user listUser[30];
int countUserInList = 0;
int page_user = 1;
void readListUserData() {
	int k = 0;
	ifstream infile;
	//cin.ignore();

	infile.open("user.txt", ios_base::in);
	/*infile.ignore();
	infile.ignore();
	infile.ignore();*/
	while (infile.eof() != true) {
		string username, pass, id, mail, name, gender, number, bdate, addr, per, pos;
		getline(infile, id, ',');
		getline(infile, username, ',');
		getline(infile, pass, ',');
		listUser[k].setUsername(username);
		listUser[k].setPassword(pass);
		getline(infile, mail, ',');
		getline(infile, name, ',');
		getline(infile, gender, ',');
		getline(infile, number, ',');
		getline(infile, bdate, ',');
		getline(infile, addr, ',');
		getline(infile, per, ',');
		getline(infile, pos);
		listUser[k].setAnotherInfo(id, mail, name, gender, number, bdate, addr, per, pos);
		/*gotoXY(0, k); cout << listUser[k].Tostring();
		getchar();*/
		k++;
		countUserInList = k;
	};
	infile.close();
	if (countUserInList % 8 == 0) page_user = countUserInList / 8;
	else page_user = countUserInList / 8 + 1;
}

void writeUserData() {
	fstream writedata;
	writedata.open("user.txt", ios::out);
	for (int i = 0; i < countUserInList; i++) {
		writedata << listUser[i].Tostring();
		if (i != countUserInList - 1) writedata << endl;
	}
	
	writedata.close();
}










//void deleteFood() {
//	clearSpaceBehindFunc();
//	string data;
//	gotoXY(4, 10); cout << "Nhap ten hoac ID muon xoa :";
//	cin.ignore();
//	getline(cin, data);
//
//
//	L1.deleteNode(data);
//	clearLoadData();
//	countUserInList--;
//	L1.count--;
//	writeUserData()();
//	readListUserData();
//	L1.showDataUser_page(1);
//}


void drawFrameDataOfUser() {
	SetColor(11);
	for (int x = 0; x <= 145; x++) {
		gotoXY(x, 0);
		cout << char(196);
		gotoXY(x, 20);
		cout << char(196);
	}
	for (int y = 1; y <= 20; y++) {
		gotoXY(0, y);
		cout << char(179);
		gotoXY(145, y);
		cout << char(179);
	}
	gotoXY(0, 0); cout << char(218);
	gotoXY(145, 0); cout << char(191);
	gotoXY(145, 20); cout << char(217);
	gotoXY(0, 20); cout << char(192);

	int x = 1, y = 2;
	gotoXY(x,y); cout << " ID ";
	gotoXY(x + 5, y); cout << "USERNAME";
	gotoXY(x + 5 + 15, y); cout << "MAT KHAU";
	gotoXY(x + 5 + 15 + 12, y); cout << "EMAIL";
	gotoXY(x + 5 + 15 + 12 + 27, y); cout << "HO TEN";
	gotoXY(x + 5 + 15 + 12 + 27 + 17, y); cout << "GIOI TINH";
	gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11, y); cout << "SDT";
	gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12, y); cout << "NGAYSINH";
	gotoXY(x + 5 + 15 + 12 + 27 + 17 +	11 + 12 + 15, y); cout << "DIA CHI";
	gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12 + 15 + 15 , y); cout << "VI TRI";
	SetColor(63);
}

void showDataUser_page(int pageIndex) {
	gotoXY(70, 19); cout << "Trang[" << pageIndex << "]/[" << page_user << "]";
	int i = 0;
	int tempPage;
	if (countUserInList % 8 == 0) tempPage = countUserInList / 8;
	else tempPage = countUserInList / 8 + 1; int y = 2,x=1;
	if (tempPage == pageIndex) {
		for (int PageItem = 8 * (pageIndex - 1); PageItem < countUserInList; PageItem++) {
			y+=2;
			gotoXY(x, y); cout << listUser[PageItem].getInfo("ID");//" ID ";
			gotoXY(x + 5, y); cout << listUser[PageItem].getInfo("username"); //"USERNAME";
			gotoXY(x + 5 + 15, y); cout << listUser[PageItem].getInfo("password"); //"MAT KHAU";
			gotoXY(x + 5 + 15 + 12, y); cout << listUser[PageItem].getInfo("email"); //"EMAIL";
			gotoXY(x + 5 + 15 + 12 + 27, y); cout << listUser[PageItem].getInfo("name"); //"HO TEN";
			gotoXY(x + 5 + 15 + 12 + 27 + 17, y); cout << listUser[PageItem].getInfo("gender"); //"GIOI TINH";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11, y); cout << listUser[PageItem].getInfo("pNum"); //"SDT";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12, y); cout << listUser[PageItem].getInfo("bdate");// "NGAYSINH";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12 + 15, y); cout << listUser[PageItem].getInfo("address"); //"DIA CHI";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12 + 15 + 15, y); cout << listUser[PageItem].getInfo("position"); //"VI TRI";
		}
	}
	else {
		for (int PageItem = 8 * (pageIndex - 1); PageItem < 8 * (pageIndex - 1) + 8; PageItem++) {
			y+=2;
			gotoXY(x, y); cout << listUser[PageItem].getInfo("ID");//" ID ";
			gotoXY(x + 5, y); cout << listUser[PageItem].getInfo("username"); //"USERNAME";
			gotoXY(x + 5 + 15, y); cout << listUser[PageItem].getInfo("password"); //"MAT KHAU";
			gotoXY(x + 5 + 15 + 12, y); cout << listUser[PageItem].getInfo("email"); //"EMAIL";
			gotoXY(x + 5 + 15 + 12 + 27, y); cout << listUser[PageItem].getInfo("name"); //"HO TEN";
			gotoXY(x + 5 + 15 + 12 + 27 + 17, y); cout << listUser[PageItem].getInfo("gender"); //"GIOI TINH";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11, y); cout << listUser[PageItem].getInfo("pNum"); //"SDT";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12, y); cout << listUser[PageItem].getInfo("bdate");// "NGAYSINH";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12 + 15, y); cout << listUser[PageItem].getInfo("address"); //"DIA CHI";
			gotoXY(x + 5 + 15 + 12 + 27 + 17 + 11 + 12 + 15 + 15, y); cout << listUser[PageItem].getInfo("position"); //"VI TRI";
		}
	}
}	

void clear_frame_data_user() {
	SetColor(0);
	for (int x = 1; x < 144; x++) {
		for (int y = 3; y < 19; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void clear_input_user() {
	SetColor(0);
	for (int x = 45; x < 120; x++) {
		for (int y = 22; y < 28; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void add_user() {
	string username, pass, id, mail, name, gender, number, bdate, addr, per, pos;
	id = listUser[countUserInList - 1].getInfo("ID");
	id = "KH" + std::to_string((int)(id.at(2) - '0') +1);
	int xx = 45, yy = 22;
	cin.ignore();
	gotoXY(45, 22); cout << "ID >" << id;
	gotoXY(xx, yy + 1); cout << "Nhap ten nguoi dung > "; getline(cin, username);
	gotoXY(xx, yy + 2); cout << "Nhap mat khau       > "; getline(cin, pass);
	gotoXY(xx, yy + 3); cout << "Nhap email > "; getline(cin, mail);
	gotoXY(xx, yy + 4); cout << "Nhap ten   > "; getline(cin, name);
	gotoXY(xx, yy + 5); cout << "Nhap gioi tinh      > "; getline(cin, gender);
	
	gotoXY(xx + 35, yy);	 cout << "Nhap so dien thoai   > "; getline(cin, number);
	gotoXY(xx + 35, yy + 1); cout << "Nhap ngay sinh       > "; getline(cin, bdate);
	gotoXY(xx + 35, yy + 2); cout << "Nhap dia chi         > "; getline(cin, addr);
	gotoXY(xx + 35, yy + 3); cout << "Nhap quyen truy cap  > "; getline(cin, per);
	gotoXY(xx + 35, yy + 4); cout << "Nhap vi tri lam viec > "; getline(cin, pos);

	listUser[countUserInList].setAnotherInfo(id, mail, name, gender, number, bdate, addr, per, pos);
	listUser[countUserInList].setAccount(username, pass);

	countUserInList++;
	writeUserData();
	readListUserData();
	clear_frame_data_user();
	showDataUser_page(page_user);

}

void view_page_data_user() {
	cin.ignore(); int i;
	gotoXY(45, 22); cout << "Nhap trang du lieu muon xem >"; cin >> i;
	if (i <= page_user) {
		clear_frame_data_user();
		showDataUser_page(i);
	}
	clear_input_user();
}
void startManageUser() {
	int ok = 1;
	int choose;
	do {
		SetColor(15);
		gotoXY(1, 21); cout << " 1. Them nguoi dung ";
		gotoXY(1, 22); cout << " 2. Sua thong tin ";
		gotoXY(1, 23); cout << " 3. Xoa nguoi dung ";
		gotoXY(1, 24); cout << " 4. Tim kiem thong tin";
		gotoXY(1, 25); cout << " 5. Xem trang du lieu";
		gotoXY(1, 26); cout << " 0. Ve trang chu";
		gotoXY(1, 27); cout << "Chon chuc nang" << char(175) << " "; cin >> choose;
		switch (choose) {
		case 1: {
			//showDataUser_page(1);
			add_user();

			//getchar();
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			view_page_data_user();
			break;
		}
		case 0: {
			ok = 0;
			break;
		}
		}
	} while (ok);

}
void manageUser() {
	system("cls");

	readListUserData();
	//L1.showDataUser_page(pageNow);
	//loadData();
	drawFrameDataOfUser();
	showDataUser_page(1);
	startManageUser();
	system("cls");
	//for(int i = 0; i < countUserInList ;i++)
	//gotoXY(0, 0); cout << L1;


	//gotoXY(0, 0); cout << L1;

	/*food f1("id1 ", "giai khat ", "sting ", "chai ", 11, 11);

	gotoXY(0, 0); L1.addNewFood(f1);
	cin >> f1;
	cout << "hii";
	L1.addNewFood(f1);
	cout << L1;
	cin >> f1;
	L1.addNewFood(f1);
	cout << L1;*/

}