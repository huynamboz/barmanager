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
		gotoXY(x, 21);
		cout << char(196);
	}
	for (int y = 1; y <= 21; y++) {
		gotoXY(0, y);
		cout << char(179);
		gotoXY(145, y);
		cout << char(179);
	}
	gotoXY(0, 0); cout << char(218);
	gotoXY(145, 0); cout << char(191);
	gotoXY(145, 21); cout << char(217);
	gotoXY(0, 21); cout << char(192);

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
void clear_input_data() {
	SetColor(0);
	for (int x = 35; x < 150; x++) {
		for (int y = 22; y < 40; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

void clear_menu_manageUser() {
	SetColor(0);
	for (int x = 0; x < 30; x++) {
		for (int y = 22; y < 40; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void showDataUser_page(int pageIndex) {
	gotoXY(70, 20); cout << "Trang[" << pageIndex << "]/[" << page_user << "]";
	int i = 0;
	int tempPage;
	if (countUserInList % 8 == 0) tempPage = countUserInList / 8;
	else tempPage = countUserInList / 8 + 1; int y = 2,x=1;
	if (tempPage == pageIndex) {
		for (int PageItem = 8 * (pageIndex - 1); PageItem < countUserInList; PageItem++) {
			y+=2;
			gotoXY(x, y); cout << listUser[PageItem].getInfo("id");//" ID ";
			gotoXY(x + 5, y); cout << listUser[PageItem].getInfo("username"); //"USERNAME";
			gotoXY(x + 5 + 15, y); cout << "xxxxxx";//listUser[PageItem].getInfo("password"); //"MAT KHAU";
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
			gotoXY(x, y); cout << listUser[PageItem].getInfo("id");//" ID ";
			gotoXY(x + 5, y); cout << listUser[PageItem].getInfo("username"); //"USERNAME";
			gotoXY(x + 5 + 15, y); cout << "xxxxxx";// listUser[PageItem].getInfo("password"); //"MAT KHAU";
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
		for (int y = 23; y < 35; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}
void add_user() {
	clear_input_user();
	string username, pass, id, mail, name, gender, number, bdate, addr, per, pos;
	id = listUser[countUserInList - 1].getInfo("id");
	string id1 = "";
	id = "KH" + std::to_string(stoi(id.substr(2,id.length() - '0')) +1);
	int xx = 45, yy = 24;
	cin.ignore();
	gotoXY(45, yy); cout << "ID >" << id;
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
	clear_input_user();
	cin.ignore(); int i;
	gotoXY(45, 23); cout << "Nhap trang du lieu muon xem >"; cin >> i;
	if (i <= page_user) {
		clear_frame_data_user();
		showDataUser_page(i);
	}
	clear_input_user();
}


void delete_user() {
	clear_input_user();
	int xx = 45, yy = 24; string id;
	cin.ignore();
	gotoXY(45, yy); cout << "Nhap id muon xoa > ";cin >> id;
	bool checkID = false;
	//gotoXY(80, 22); cout <<listUser[0].getInfo("id");
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkID = true;
		}
	}

	if (checkID) {
		string cfm = "";
		gotoXY(xx, yy++); cout << "Ban chac chan muon xoa chua(y/n) ? ";
		cin >> cfm;
		if (cfm == "y") {
			for (int i = 0; i < countUserInList; i++) {
				if (listUser[i].getInfo("id") == id) {
					for (int j = i; j < countUserInList - 1; j++) {
						listUser[j] = listUser[j + 1];
					}
				}
			}
			countUserInList--;
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(page_user);
			gotoXY(xx, yy++); cout << "Da xoa thanh cong !";
		}
		else {
			gotoXY(xx, yy++); cout << "Ban da huy";
		}
		
	}
	else {
		gotoXY(xx, yy+=2); cout << "Nhap sai ID !";
	}

}

void edit_username() {
	 string id;
	 bool checkId = false;
	 int xx = 45, yy = 24;
	 int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}
		
	}
	if (checkId) {
		string name;
		gotoXY(xx, ++yy); cout << "Username cu la : " << listUser[indexEdit].getUsername();
		gotoXY(xx, ++yy); cout << "Nhap username moi : "; cin.ignore();
		getline(cin, name);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setUsername(name);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
				gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_password() {
	string id;
	bool checkId = false;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	int xx = 45, yy = 24;
	if (checkId) {
		string pass="", pass1="";
		reInputpass:
		int xx = 45, yy = 24;
		gotoXY(xx, ++yy); cout << "Nhap mat khau cu : "; cin >> pass1;
		if (listUser[indexEdit].getPassword() != pass1) {
			gotoXY(xx, yy + 1); cout << "Nhap sai mat khau cu -> Hay nhap lai";
			goto reInputpass;
		} 
		gotoXY(xx, yy + 1); cout << "                                     ";
		gotoXY(xx, ++yy); cout << "Nhap mat khau moi : "; cin.ignore();
		getline(cin, pass);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setPassword(pass);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_mail() {
	string id;
	bool checkId = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	if (checkId) {
		string mail;
		gotoXY(xx, ++yy); cout << "Email cu la : " << listUser[indexEdit].getInfo("email");
		gotoXY(xx, ++yy); cout << "Nhap email moi : "; cin.ignore();
		getline(cin, mail);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("email",mail);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_name() {
	string id;
	bool checkId = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	if (checkId) {
		string name;
		gotoXY(xx, ++yy); cout << "Ho ten cu la : " << listUser[indexEdit].getInfo("name");
		gotoXY(xx, ++yy); cout << "Nhap ho ten moi : "; cin.ignore();
		getline(cin, name);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("name",name);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_gender() {
	string id;
	bool checkId = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	if (checkId) {
		string gender;
		gotoXY(xx, ++yy); cout << "Gioi tinh hien tai la : " << listUser[indexEdit].getInfo("gender");
		gotoXY(xx, ++yy); cout << "Nhap gioi tinh moi : "; cin.ignore();
		getline(cin, gender);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("gender",gender);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_sdt() {
	string id;
	bool checkId = false;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	int xx = 45, yy = 24;
	if (checkId) {
		string sdt = "", pass1 = "";
	reInputsdt:
		int xx = 45, yy = 24;
		gotoXY(xx, ++yy); cout << "So dien thoai hien tai : "; cout << listUser[indexEdit].getInfo("pNum");
		gotoXY(xx, ++yy); cout << "Nhap mat khau cu : "; cin >> sdt;
		if (sdt.length() > 11 || sdt.length() < 10 || sdt[0] != '0') {
			gotoXY(xx, yy + 1); cout << "Hay nhap dung dinh dang sdt";
			goto reInputsdt;
		}
		gotoXY(xx, yy + 1); cout << "                                     ";
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("pNum",sdt);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_date() {
	string id;
	bool checkId = false;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	int xx = 45, yy = 24;
	if (checkId) {
		string day = "", pass1 = "";
	reInputsdt:
		int xx = 45, yy = 24;
		gotoXY(xx, ++yy); cout << "Ngay sinh hien tai : "; cout << listUser[indexEdit].getInfo("bdate");
		gotoXY(xx, ++yy); cout << "Nhap ngay sinh moi : "; cin >> day;
		gotoXY(xx, yy + 1); cout << "                                     ";
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("bdate", day);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_addr() {
	string id;
	bool checkId = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	if (checkId) {
		string addr;
		gotoXY(xx, ++yy); cout << "Dia chi cu la : " << listUser[indexEdit].getInfo("address");
		gotoXY(xx, ++yy); cout << "Nhap dia chi moi : "; cin.ignore();
		getline(cin, addr);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("address",addr);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_pos() {
	string id;
	bool checkId = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	gotoXY(45, 24); cout << "Nhap id > "; cin >> id;
	for (int i = 0; i < countUserInList; i++) {
		if (listUser[i].getInfo("id") == id) {
			checkId = true;
			indexEdit = i;
			break;
		}

	}
	if (checkId) {
		string addr;
		gotoXY(xx, ++yy); cout << "Vi tri lam viec cu la : " << listUser[indexEdit].getInfo("position");
		gotoXY(xx, ++yy); cout << "Nhap dia chi moi : "; cin.ignore();
		getline(cin, addr);
		gotoXY(xx, yy++); cout << "Ban chac chan muon thay doi chua(y/n) ? ";
		string cfm; cin >> cfm;
		if (cfm == "y") {
			listUser[indexEdit].setInfo("position", addr);
			writeUserData();
			readListUserData();
			clear_frame_data_user();
			showDataUser_page(1);
		}
	}
	else {
		SetColor(0);
		for (int xx = 45; xx < 70; xx++) {
			gotoXY(xx, yy); cout << char(219);
		}
		SetColor(127);
		gotoXY(xx, yy); cout << "KHONG CO DU LIEU !";
	}
}
void edit_data_user() {
	int ok = 1;
	do {
		SetColor(0);
		for (int x = 0; x < 25; x++) {
			for (int y = 22; y < 40; y++) {
				gotoXY(x, y); cout << char(219);
			}
		}
		SetColor(127);
		int yy = 22;
		gotoXY(1, ++yy); cout << " 1. Sua username ";
		gotoXY(1, ++yy); cout << " 2. Sua password ";
		gotoXY(1, ++yy); cout << " 3. Sua email ";
		gotoXY(1, ++yy); cout << " 4. Sua ho ten";
		gotoXY(1, ++yy); cout << " 5. Sua gioi tinh";
		gotoXY(1, ++yy); cout << " 6. Sua so dien thoai";
		gotoXY(1, ++yy); cout << " 7. Sua ngay sinh";
		gotoXY(1, ++yy); cout << " 8. Sua dia chi";
		gotoXY(1, ++yy); cout << " 9. Sua vi tri lam viec";
		gotoXY(1, ++yy); cout << " 0. Ve trang chu";
		int choose = 0;
		gotoXY(1, ++yy); cout << "Chon chuc nang" << char(175) << " "; cin >> choose;
		switch (choose) {
		case 1: {
			clear_input_user();
			edit_username();
			break;
		}
		case 2: {
			clear_input_user();
			edit_password();
			break;
		}
		case 3: {
			clear_input_data();
			edit_mail();
			break;
		}
		case 4: {
			clear_input_data();
			edit_name();
			break;
		}
		case 5: {
			clear_input_data();
			edit_gender();
			break;
		}
		case 6:
			clear_input_data();
			edit_sdt();
			break;
		case 7:
			clear_input_data();
			edit_date();
			break;
		case 8:
			clear_input_data();
			edit_addr();
			break;
		case 9:
			clear_input_data();
			edit_pos();
			break;
		case 0: {
			ok = 0;
			break;
		}
		}
	} while (ok);
}


void find_info_staff() {
	string findT; //findT = findText
	cin.ignore();
	bool check = false;
	int xx = 45, yy = 24;
	int indexEdit = 0;
	here:
	gotoXY(45, 24); cout << "                                                        ";
	gotoXY(45, 24); cout << "Nhap thong tin can tim/ nhap 0 de huy > "; 
	getline(cin, findT);
	check = false;
	if (findT != "0") {
		int xx2 = 35;

		SetColor(0);
		for (int x = 35; x < 145; x++) {
			for (int y = 25; y < 40; y++) {
				gotoXY(x, y); cout << char(219);
			}
		}
		SetColor(127);
		xx = 45, yy = 24;
		gotoXY(45, 24);
		for (int i = 0; i < countUserInList; i++) {
			if (listUser[i].getInfo("id") == findT
				|| listUser[i].getInfo("email") == findT
				|| listUser[i].getInfo("username") == findT
				|| listUser[i].getInfo("name") == findT
				|| listUser[i].getInfo("gender") == findT
				|| listUser[i].getInfo("pNum") == findT
				|| listUser[i].getInfo("bdate") == findT
				|| listUser[i].getInfo("address") == findT
				|| listUser[i].getInfo("position") == findT) {
				gotoXY(xx2, ++yy);
				cout << "Ten :" << listUser[i].getInfo("name")
					<< " || Gioi tinh : " << listUser[i].getInfo("gender")
					<< " || Vi tri lam viec : " << listUser[i].getInfo("position")
					<< " || Dia chi : " << listUser[i].getInfo("address")
					<< " || SDT : " << listUser[i].getInfo("pNum");
				gotoXY(xx2, ++yy); cout << "------------------------------------------------------------------------------------------------------------------";
				check = true;
			}
		}
		if (check != true) {
			gotoXY(45, 25); cout << "Khon tim thay thong tin !";
		}
		goto here;
	} else clear_input_data();
}

void startManageUser() {
	int ok = 1;
	int choose;
	do {
		int yy = 23;
		SetColor(15);
		clear_menu_manageUser();
		gotoXY(1, yy); cout << " 1. Them nguoi dung ";
		gotoXY(1, ++yy); cout << " 2. Sua thong tin ";
		gotoXY(1, ++yy); cout << " 3. Xoa nguoi dung ";
		gotoXY(1, ++yy); cout << " 4. Tim kiem thong tin";
		gotoXY(1, ++yy); cout << " 5. Xem trang du lieu";
		gotoXY(1, ++yy); cout << " 0. Ve trang chu";
		gotoXY(1, ++yy); cout << "Chon chuc nang" << char(175) << " "; cin >> choose;
		switch (choose) {
		case 1: {
			//showDataUser_page(1);
			add_user();
			clear_input_data();
			//getchar();
			break;
		}
		case 2: {
			edit_data_user();
			break;
		}
		case 3: {
			delete_user();
			clear_input_data();
			break;
		}
		case 4: {
			find_info_staff();
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