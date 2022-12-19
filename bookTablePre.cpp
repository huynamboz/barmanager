
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
	for (int x = 0; x < 35; x++) {
		for (int y = 9; y < 40; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

void clear_menuBookPre_form() {
	SetColor(0);
	for (int x = 0; x < 40; x++) {
		for (int y = 1; y < 10; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

int checkPhuThu(int d, int m, int y) {
	barCalender ListCal[100];
	int k = 0;
	int countList = k;
	ifstream infile;
	infile.open("calendar.txt", ios_base::in);
	while (infile.eof() != true) {
		string day, detail;int  phuthu =0;
		getline(infile, day, ',');
		getline(infile, detail, ',');
		infile >> phuthu;
		infile.ignore();
		ListCal[k].setAnotherInfo(day, detail, phuthu);
		/*gotoXY(0, k); cout << listUser[k].Tostring();
		getchar();*/
		k++;
		countList = k;
	};
	infile.close();
	string date = to_string(d)+"/" + to_string(m)+"/" + to_string(y);
	for (int i = 0; i < countList; i++) {
		if (ListCal[i].getInfo("ngay") == date) {
			return stoi(ListCal[i].getInfo("phuthu"));
		}
	}
	return 0;
}

int up(string u) {
	int sum = 0;
	int k = 0;
	for (int i = u.length() - 1; i >= 0; i--) {
		sum += (u[i] - '0') * 10 * k;
		k++;
	}
	return sum;
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
	TY =10;
	SetColor(0);
	for (int x = 0; x < 30; x++) {
		gotoXY(x, 10); cout << char(219);
	} SetColor(127);
	gotoXY(1, TY); cout << " Nhap ten > "; getline(cin, name);
	gotoXY(1, TY+1); cout << " Nhap so dien thoai > "; getline(cin, sdt);

	int d, m, y;

here:
	SetColor(0);
	for (int x = 0; x < 30; x++) {
		gotoXY(x, TY+2); cout << char(219);
	} SetColor(127); 
	gotoXY(1, TY + 2); cout << " Nhap ngay muon dat >"; cin >> d >> m >> y;
	cin.ignore();
	bool checkDay = true;
	if (y == aTime2->tm_year + 1900) {
		if (m >= aTime2->tm_mon) {
			if (d >= aTime2->tm_mday) {
				ngay = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
			}
			else checkDay = false;
		}
		else checkDay = false;
	}
	else checkDay = false;
	
	if (checkDay == false) {
		cout << " Nhap sai ngay !";
		goto here;
	}
	else cout << "                           ";
	int pt = checkPhuThu(d, m, y);
		gotoXY(1, TY + 3); cout << " Phi phu thu : " << pt <<"d";
	gotoXY(1, TY + 4); cout << " Nhap ban > "; getline(cin, ban);
	ban = "ban " + ban;
	gotoXY(1, TY+5); cout << " Nhap ghichu > "; getline(cin, ghichu);
	
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
		gotoXY(0, 10); cout << " Dat ban thanh cong";

	} 
	else
	{
		
		clearFormDataOfBookPre();
		clearInputDataOfBookPre();gotoXY(0, 10); cout << " Ban da co nguoi dat truoc";
		showData_bookpre();
	}
	
}
void clearEditOfBookPre() {
	SetColor(0);
	for (int x = 0; x < 43; x++) {
		gotoXY(x, 10); cout << char(219);
	} SetColor(127);

}

void editValueOfBookPre(string id, string whatEdit) {
	bool checkId = false; 
	for (int i = 0; i < slTableBooked; i++) {
		if (Listtable[i].getInfo("id") == id) {
			checkId = true;
		}
	}
	if (checkId) {
		if (whatEdit == "ten") {
			string name;


			clearEditOfBookPre();


			gotoXY(0, 10); cout << " Nhap ten moi >"; getline(cin, name);

			string cfrm = "";

			clearEditOfBookPre();


			gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
			if (cfrm == "y") {

				for (int i = 0; i < slTableBooked; i++) {
					if (Listtable[i].getInfo("id") == id) {
						Listtable[i].editData(whatEdit, name);
						break;
					}
				}
				writeBookPreData();
				readDatatableOrdered();
				clearFormDataOfBookPre();
				showData_bookpre();
				SetColor(0);
				for (int x = 0; x < 30; x++) {
					gotoXY(x, 10); cout << char(219);
				} SetColor(127);
				gotoXY(0, 10); cout << " Da thay doi thanh cong !";
			}
		}
		/*edit sdt ------------------------------*/
		else if (whatEdit == "sdt") {
			string sdt;


			clearEditOfBookPre();


			gotoXY(0, 10); cout << " Nhap so dien thoai moi >"; getline(cin, sdt);

			string cfrm = "";

			clearEditOfBookPre();


			gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
			if (cfrm == "y") {
				for (int i = 0; i < slTableBooked; i++) {
					if (Listtable[i].getInfo("id") == id) {
						Listtable[i].editData(whatEdit, sdt);
						break;
					}
				}
				writeBookPreData();
				readDatatableOrdered();
				clearFormDataOfBookPre();
				showData_bookpre();
				clearEditOfBookPre();
				gotoXY(0, 10); cout << " Da thay doi thanh cong !";
			}
		}
		/*edit ngay ------------------------------*/
		else if (whatEdit == "ngay") {
			string ngay;
			int d, m, y;
		here1:
			clearEditOfBookPre();
			gotoXY(0, 10); cout << " Nhap lai ngay vd:21 12 2022 >"; 
			cin >> d >> m >> y;
			cin.ignore();
			bool checkDay = true;
			if (y == aTime2->tm_year + 1900) {
				if (m >= aTime2->tm_mon  && m <=12 && m >=0) {
					if (d >= aTime2->tm_mday && d <=31) {
						ngay = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
					}
					else checkDay = false;
				}
				else checkDay = false;
			}
			else checkDay = false;
			if (checkDay == false) {
				cout << " Nhap sai ngay !";
				goto here1;
			}
			int pt = checkPhuThu(d, m, y);
			if (pt > 0) {
				gotoXY(1, 9); cout << "Phi phu thu " << pt;
			}
			string cfrm = "";
			clearEditOfBookPre();
			gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
			if (cfrm == "y") {
				for (int i = 0; i < slTableBooked; i++) {
					if (Listtable[i].getInfo("id") == id) {
						Listtable[i].editData(whatEdit, ngay);
						Listtable[i].editData("phuthu", to_string(pt));
						break;
					}
				}
				SetColor(0);
				for (int x = 0; x < 40; x++) {
					gotoXY(x, 11); cout << char(219);
				} SetColor(127);
				writeBookPreData();
				readDatatableOrdered();
				clearFormDataOfBookPre();
				showData_bookpre();
				clearEditOfBookPre();
				gotoXY(0, 10); cout << " Da thay doi thanh cong !";
			}
		}
		/*edit ban ------------------------------*/
		else if (whatEdit == "ban") {
		string ban;


		clearEditOfBookPre();
		here2:
		int bNum = 0;

		SetColor(0);
		for (int x = 0; x < 30; x++) {
			gotoXY(x, 10); cout << char(219);
		} SetColor(127);

		gotoXY(0, 10); cout << " Nhap ban moi >"; cin >> bNum;
		if (0 > bNum || bNum > 20) {
			cout << " Ban khong hop le           ";
			goto here2;
		}
		SetColor(0);
		for (int x = 0; x < 30; x++) {
			gotoXY(x, 10); cout << char(219);
		} SetColor(127);
		bool checktable = true;
		ban = "ban " + to_string(bNum); 
		for (int i = 0; i < slTableBooked; i++) {
			
			if (Listtable[i].getInfo("ban") == ban) {
				checktable = false;
			}
		}


		if (checktable == false) {
			gotoXY(1,11); cout << " Ban da co nguoi dat !        ";
			goto here2;
		}
		string cfrm = "";

		clearEditOfBookPre();


		gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
		if (cfrm == "y") {

			for (int i = 0; i < slTableBooked; i++) {
				if (Listtable[i].getInfo("id") == id) {
					Listtable[i].editData(whatEdit, ban);
					break;
				}
			}

			writeBookPreData();
			readDatatableOrdered();
			clearFormDataOfBookPre();
			showData_bookpre();

			clearEditOfBookPre();

			SetColor(0);
			for (int x = 0; x < 30; x++) {
				gotoXY(x, 10); cout << char(219);
			} SetColor(127);
			gotoXY(0, 10); cout << " Da thay doi thanh cong !";
		}
		}
		//----------------------------------------------------//
		else if (whatEdit == "ghichu") {
		string ghichu;


		clearEditOfBookPre();


		gotoXY(0, 10); cout << " Nhap ghi chu moi >"; getline(cin, ghichu);

		

		clearEditOfBookPre();

		string cfrm = "";
		gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
		if (cfrm == "y") {
			for (int i = 0; i < slTableBooked; i++) {
				if (Listtable[i].getInfo("id") == id) {
					Listtable[i].editData(whatEdit, ghichu);
					break;
				}
			}
			writeBookPreData();
			readDatatableOrdered();
			clearFormDataOfBookPre();
			showData_bookpre();
			clearEditOfBookPre();
			gotoXY(0, 10); cout << " Da thay doi thanh cong !";
		}
		}

	}
	else {

		clearEditOfBookPre();

		gotoXY(0, 10); cout << " Khong co du lieu";
	}
	

}

void deleteDataBookPre() {
	//clear_menuBookPre_form();
	clearEditOfBookPre();
	gotoXY(0, 10); cout << " Nhap id can xoa >"; string id; cin >> id;
	
	string cfrm = "";
	gotoXY(0, 10); cout << " Ban co chac chan chua (y/n) >"; cin >> cfrm;
	if (cfrm == "y") {
		for (int i = 0; i < slTableBooked; i++) {
			if (Listtable[i].getInfo("id") == id) {
				for (int j = i; j < slTableBooked - 1; j++) {
					Listtable[j] = Listtable[j + 1];
				}
				slTableBooked--;
				break;
			}
		}
		writeBookPreData();
		readDatatableOrdered();
		clearFormDataOfBookPre();
		showData_bookpre();
		clearEditOfBookPre();
	}
}


void editDataBookPre() {
	int ok = 1;
	do {
		clear_menuBookPre_form();
	//	clearInputDataOfBookPre();
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
		switch (choose)
		{
		case 1: {
			//clearInputDataOfBookPre();
			clearEditOfBookPre();
			gotoXY(0, 10); cout << "Nhap id can sua >"; string id; cin >> id;
			cin.ignore();
			editValueOfBookPre(id, "ten");
			break;

		}
			//inputInformation_bookPre();
		case 2:
		{
			clearEditOfBookPre();

			gotoXY(0, 10); cout << "Nhap id can sua >"; string id; cin >> id;
			cin.ignore();
			editValueOfBookPre(id, "sdt");

			break;
		
		}
		case 3: {
			clearEditOfBookPre();
			gotoXY(0, 10); cout << "Nhap id can sua >"; string id; cin >> id;
			cin.ignore();
			editValueOfBookPre(id, "ngay");
			break;
		}
		case 4: {
			clearEditOfBookPre();
			gotoXY(0, 10); cout << "Nhap id can sua >"; string id; cin >> id;
			cin.ignore();
			editValueOfBookPre(id, "ban");
			break;
		}
		case 5: {
			clearEditOfBookPre();
			gotoXY(0, 10); cout << "Nhap id can sua >"; string id; cin >> id;
			cin.ignore();
			editValueOfBookPre(id, "ghichu");
			break;
		}
		case 0: {
			clear_menuBookPre_form();
			SetColor(0);
			for (int x = 0; x < 30; x++) {
				gotoXY(x, 10); cout << char(219);
			} SetColor(127);
			ok = 0;
			break;
		}
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
		//cout << endl << "3. Hien thi danh sach dat ban";
		cout << endl << "3. Xoa thong tin dat ban";
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
		case 3:
			deleteDataBookPre();
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