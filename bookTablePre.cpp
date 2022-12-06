
#include "dontedit.h"
#include "Header.h"
#pragma warning(disable : 4996)

time_t theTime2 = time(NULL);
struct tm* aTime2 = localtime(&theTime2);
bookTablePre Listtable[50];
int slTableBooked = 0;

void readDatatableOrdered() {
	int k = 0;
	ifstream infile;
	
	infile.open("dataBookPre.txt", ios_base::in);
	//infile.ignore();
	//infile.ignore();
	//infile.ignore();
	while (infile.eof() != true) {
		string id,name, sdt,time, day, table, phuthu, note;
		getline(infile, id, ',');
		getline(infile, name, ',');
		getline(infile, sdt, ',');
		getline(infile, time, ',');
		getline(infile, day, ',');
		getline(infile, table, ',');
		getline(infile, phuthu, ',');
		getline(infile, note);
		Listtable[k].setAllInfo(id,name, sdt,time, day, table, stoi(phuthu), note);
		k++;
		slTableBooked = k;
	}
	infile.close();
}

void showData_bookpre() {
	gotoXY(45, 1); cout << "id";
	gotoXY(50, 1); cout << "Ten";
	gotoXY(65, 1); cout << "so dien thoai";
	gotoXY(80, 1); cout << "thoi gian";
	gotoXY(95, 1); cout << "Ngay dat";
	gotoXY(110, 1); cout << "Ban";
	gotoXY(120, 1); cout << "Phu thu";
	gotoXY(130, 1); cout << "Ghi chu";
	int y = 3;
	SetColor(127);
	//gotoXY(50, 8); cout << Listtable[0].getInfo("phuthu");

	for (int i = 0; i < slTableBooked; i++) {
		gotoXY(45, y); cout << Listtable[i].getInfo("id");
		gotoXY(50, y); cout << Listtable[i].getInfo("ten");
		gotoXY(65, y); cout << Listtable[i].getInfo("sdt");
		gotoXY(80, y); cout << Listtable[i].getInfo("thoigian");
		gotoXY(95, y); cout << Listtable[i].getInfo("ngay");
		gotoXY(110, y); cout << Listtable[i].getInfo("ban");
		gotoXY(120, y); cout << Listtable[i].getInfo("phuthu");
		gotoXY(130, y); cout << Listtable[i].getInfo("ghichu");
		y+=2;
	}
}



void writeBookPreData() {
	fstream writedata;
	writedata.open("dataBookPre.txt", ios::out);
	for (int i = 0; i < slTableBooked; i++) {
		writedata << Listtable[i].toString();
		if (i != slTableBooked - 1) writedata << endl;
	}
	writedata.close();
}
void clearFormDataOfBookPre() {
	SetColor(0);
	for (int x = 40; x < 144; x++) {
		for (int y = 2; y < 40; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void clearInputDataOfBookPre() {
	SetColor(0);
	for (int x = 1; x < 35; x++) {
		for (int y = 9; y < 20; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

void clear_menuBookPre_form() {
	SetColor(0);
	for (int x = 1; x < 50; x++) {
		for (int y = 1; y < 20; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void inputInformation_bookPre() {
	string id,name, sdt, ngay, ban,ghichu;
	cin.ignore(); SetColor(127);
	int TY = 8, TX = 1; bool checkHave = false;
	/*gotoXY(TX, TY); cout << " Cac ban trong :";
	TY++;
	int count = 1;
	for (int i = 1; i < 21; i++) {
		
		for (int j = 0; j < slTableBooked; j++) {
			if (Listtable[j].getInfo("ban") == ("ban "+ to_string(i))) {
				checkHave = true;
			}
		}
		if (checkHave != true) {
			count++;
			gotoXY(TX, TY); cout << "ban " << i;
			TY++;
		}
		checkHave = false;
		if (count % 4 ==0) {
			TY = 9;
			TX += 7;
		}
	}*/
	TY =15;
	gotoXY(1, TY); cout << "Nhap ten > "; getline(cin, name);
	gotoXY(1, TY+1); cout << "Nhap so dien thoai > "; getline(cin, sdt);
	gotoXY(1, TY+2); cout << "Nhap ngay > "; getline(cin, ngay);
	gotoXY(1, TY+3); cout << "Nhap ban > "; getline(cin, ban);
	ban = "ban " + ban;
	gotoXY(1, TY+4); cout << "Nhap ghichu > "; getline(cin, ghichu);
	int pt = 100;
	id = to_string(stoi(Listtable[slTableBooked-1].getInfo("id"))+1);
	bool checkTableOK = true;
	for (int i = 0; i < slTableBooked; i++) {
		if (Listtable[i].getInfo("ban") == ban)
			checkTableOK = false;
	}
	if (checkTableOK) {
		string time = to_string(aTime2->tm_hour) + ":" + to_string(aTime2->tm_min);
		Listtable[slTableBooked].setAllInfo(id, name, sdt, time, ngay, ban, pt, ghichu);

		slTableBooked++;
		writeBookPreData();
		readDatatableOrdered();
		clearFormDataOfBookPre();
		clearInputDataOfBookPre();
		showData_bookpre();
	} 
	else
	{
		cout << "Ban da duoc dat";
		clearFormDataOfBookPre();
		clearInputDataOfBookPre();
		showData_bookpre();
	}
	
}


void editDataBookPre() {
	int ok = 1;
	do {
		clear_menuBookPre_form();
		SetColor(127);
		gotoXY(0, 0);
		cout << endl << " -- SUA THONG TIN -- ";
		cout << endl << "1. Sua ten";
		cout << endl << "2. Sua so dien thoai";
		cout << endl << "3. Sua ngay dat";
		cout << endl << "4. Doi ban";
		cout << endl << "5. Sua ghi chu";
		cout << endl << "0. Thoat";
		int choose;
		cout << endl << "- chon chuc nang > "; cin >> choose;
		inputInformation_bookPre();
		switch (choose)
		{
		case 1: {
			cout << "";
			string name;
			cout << endl << "Nhap ten moi >"; getline(cin, name);
			
			break;

		}
			//inputInformation_bookPre();
		case 2:
			//editDataBookPre();
			break;
		case 0:
			ok = 0;
			break;
		default:
			break;
		}
	} while (ok);
}

void menu_bookPre() {
	int ok = 1;
	do {
		SetColor(127);
		gotoXY(0, 0);
		cout << endl << " -- CHUC NANG -- ";
		cout << endl << "1. Dat ban";
		cout << endl << "2. Chinh sua thong tin dat ban";
		cout << endl << "3. Hien thi danh sach dat ban";
		cout << endl << "4. Xoa thong tin dat ban";
		cout << endl << "0. Thoat";
		int choose; 
		cout << endl << "- chon chuc nang > "; cin >> choose;
		switch (choose)
		{
		case 1:
			inputInformation_bookPre();
			break;
		case 2:
			editDataBookPre();
			break;
		case 0 :
			ok = 0;
			break;
		default:
			break;
		}
	} while (ok);
	

}
void booktablePre_menu() {
	system("cls");
	cin.ignore();
	readDatatableOrdered();
	showData_bookpre();
	menu_bookPre();
	system("cls");
}