
#include "dontedit.h"
#include "Header.h"

using namespace std;

food ListFood[100];
int slFood = 0;
void readFoodData_order() {
	int k = 0;
	ifstream infile;
	infile.open("foodData.txt", ios_base::in);
	/*infile.ignore();
	infile.ignore();*/

	string id = "", cate, name, type; int qty, cost;
	while (infile.eof() != true) {
		getline(infile, id, ',');
		getline(infile, cate, ',');
		getline(infile, name, ',');
		getline(infile, type, ',');
		infile >> qty;
		infile.ignore();
		infile >> cost;
		infile.ignore();
		ListFood[k].setAllInfo(id, cate, name, type, qty, cost);
		k++;
		slFood = k;
	};
	
	infile.close();

}
void writeFoodData_order() {
	fstream writedata;
	writedata.open("foodData.txt", ios::out);
	for (int i = 0; i < slFood; i++) {
		writedata << ListFood[i].ToString();
		if (i != slFood-1) writedata << endl;
	}
	writedata.close();
}

int max_numberTable = 20;

void clear_input_order() {
	SetColor(0);
	for (int x = 20; x < 60; x++) {
		for (int y = 1; y < 10; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

doanhthu ListItemDoanhThu[100];
int slItemInDoanhThu = 0;
void read_file_doanhthu() {
	int k = 0;
	ifstream infile;
	infile.open("doanhthu.txt", ios_base::in);
	/*infile.ignore();
	infile.ignore();*/

	string id = "", name; int qty, cost;
	while (infile.eof() != true) {
		getline(infile, id, ',');
		getline(infile, name, ',');
		infile >> qty;
		infile.ignore();
		infile >> cost;
		infile.ignore();
		ListItemDoanhThu[k].setAllInfo(id, name, qty, cost);
		k++;
		slItemInDoanhThu = k;
	};

	infile.close();
}
void order_food() {
	system("cls");
	int x = 30, y = 0;
	SetColor(78);
	gotoXY(x , y); cout << "ID";
	gotoXY(x + 10, y); cout << "TEN";
	gotoXY(x + 10 + 20, y); cout << "LOAI";
	gotoXY(x + 10 + 20 + 20, y); cout << "DON VI";
	gotoXY(x + 10 + 20 + 20 + 10, y); cout << "SO LUONG";
	gotoXY(x + 10 + 20 + 20 + 10 + 10, y); cout << "DON GIA";
	SetColor(63);

	string listIDOrder[100] ;
	int slOrder[100] ;
	int tong[100];
	int orderIndex = 0;




	int YY = 2;
	int XX = 30;
	readFoodData_order();
	for (int i = 0; i < slFood; i++) {
		gotoXY(XX, YY);  
		cout << ListFood[i].getID(); 
		gotoXY(XX + 10, YY); cout << ListFood[i].getCategory();
		gotoXY(XX + 10 + 20, YY); cout << ListFood[i].getName();
		gotoXY(XX + 10 + 20 + 20, YY); cout << ListFood[i].getType();
		gotoXY(XX + 10 + 20 + 20 + 10, YY); cout << ListFood[i].getQty();
		gotoXY(XX + 10 + 20 + 20 + 10 + 10, YY); cout << ListFood[i].getCost();
		YY += 2;
	}
	int YY2 = YY + 4; string id; int sl = 0;
	gotoXY(XX, YY2); cout << "Ten";
	gotoXY(XX + 20, YY2); cout << "So luong ";
	gotoXY(XX + 20 + 15, YY2); cout << "Don gia";
	gotoXY(XX + 20 + 15 + 15, YY2); cout << "Thanh tien";
	YY2++;
	int ok = 1;
	int sum = 0;
	do {
		SetColor(0);
		for (int x = 20; x < 100; x++) {
			for (int y = YY; y < YY + 3; y++) {
				gotoXY(x, y); cout << char(219);
			}
		}
		SetColor(127);

		here:
		gotoXY(XX, YY + 1); cout << "Nhap ID do uong muon goi / nhap 0 de thanh toan> ";
		 cin >> id; bool checkhave = true;
		for (int i = 0; i < slFood; i++) {
			if (id == "0") { ok = 0; break; }
			if (ListFood[i].getID() == id) {
				checkhave = false;
				gotoXY(XX, ++YY2); cout << ListFood[i].getName();
			}
		}
		if (ok == 0) {
			SetColor(0);
			for (int x = 20; x < 100; x++) {
				for (int y = YY; y < YY + 3; y++) {
					gotoXY(x, y); cout << char(219);
				}
			}
			SetColor(127);
			gotoXY(XX, YY + 1); cout << "Xac nhan thanh toan (y/n)? ";
			string cfm1 = "";
			cin >> cfm1;
			if (cfm1 == "y") {
				break;
			}
			else {
				ok = 1;
				goto here;
			}
		}
		if (checkhave) {
			gotoXY(XX, YY + 2); cout << "Nhap sai";
			goto here;
		}
		SetColor(0);
		for (int x = 20; x < 100; x++) {
			for (int y = YY; y < YY+3; y++) {
				gotoXY(x, y); cout << char(219);
			}
		}
		SetColor(127);
		gotoXY(XX, YY + 1); cout << "Nhap so luong > "; cin >> sl;
		for (int i = 0; i < slFood; i++) {
			if (ListFood[i].getID() == id) {
				listIDOrder[orderIndex] = id;
				slOrder[orderIndex] = sl;
				tong[orderIndex] = ListFood[i].getCost() *sl;



				orderIndex++;
				gotoXY(XX + 20, YY2); cout << sl;
				ListFood[i].setQty(ListFood[i].getQty()-sl);
				gotoXY(XX + 20 + 15, YY2); cout<< ListFood[i].getCost() ;
				gotoXY(XX + 20 + 15 + 15, YY2); cout << ListFood[i].getCost() *sl;
				sum += ListFood[i].getCost() * sl;

			}
		}

		writeFoodData_order();
		readFoodData_order();


	} while (ok);
	YY2++;

	read_file_doanhthu();
	//gotoXY(45, 70); cout << ListItemDoanhThu[0].toString();
	bool checkIndoanhthu = false;
	for (int i = 0; i < slItemInDoanhThu; i++) {
		for (int j = 0; j < orderIndex; j++) {
			if (listIDOrder[j] == ListItemDoanhThu[i].getInfo("id")) {
				ListItemDoanhThu[i].setData("sl", stoi(ListItemDoanhThu[i].getInfo("sl"))+slOrder[j]);
				ListItemDoanhThu[i].setData("tong", stoi(ListItemDoanhThu[i].getInfo("tong"))+tong[j]);
			}
		}
	}

	fstream writedata;
	writedata.open("doanhthu.txt", ios::out);
	for (int i = 0; i < slItemInDoanhThu; i++) {
		writedata << ListItemDoanhThu[i].toString();
		if (i != slItemInDoanhThu - 1) writedata << endl;
	}

	writedata.close();

	read_file_doanhthu();

	gotoXY(XX, YY2++); cout << "---------------------";
	gotoXY(XX, YY2++); cout << "Thanh tien          :" << sum;
	string cfm = "";
	gotoXY(XX, YY2++); cout << "Ban co muon goi mon nua khong (y/n)? "
		; cin >> cfm;
	if (cfm == "y") {
		SetColor(0);
		for (int x = 20; x < 100; x++) {
			for (int y = YY; y < YY + 30; y++) {
				gotoXY(x, y); cout << char(219);
			}
		}
		SetColor(127);
		goto here;
	}
	system("cls"); 

}
void order_menu() {
	order_food();
}

void order_main() {
	system("cls");
	order_menu();
	system("cls");
}
