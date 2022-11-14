#include "dontedit.h"
#include "Header.h"
using namespace std;
ListFood L1;
int countFood = 0;
void readFoodData() {
	int k = 0;
	ifstream infile;
	infile.open("foodData.txt", ios_base::in);
	infile.ignore();
	infile.ignore();

	string id = "", cate, name, type; int qty, cost;
	while (infile.eof() != true) {
		food f1;

		infile.ignore();
		getline(infile, id, ',');
		getline(infile, cate, ',');
		getline(infile, name, ',');
		getline(infile, type, ',');
		infile >> qty;
		infile.ignore();
		infile >> cost;
		
		f1.ID = id;
		f1.category = cate;
		f1.name = name;
		f1.type = type;
		f1.qty = qty;
		f1.cost = qty;
		//gotoXY(0, k+20); cout << id;
		//gotoXY(0, k); cout << f1.ToString();

		L1.addNewFood(f1);

		k++;
		countFood = k;
	};
	infile.close();

}

void inData() {

}

void drawFrame() {
	SetColor(11);
	for (int x = 50; x <= 145; x++) {
		gotoXY(x, 0);
		cout << char(196);
		gotoXY(x, 20);
		cout << char(196);
	}
	for (int y = 1; y <= 20; y++) {
		gotoXY(50, y);
		cout << char(179);
		gotoXY(145, y);
		cout << char(179);
	}
	gotoXY(50, 0); cout << char(218);
	gotoXY(145, 0); cout << char(191);
	gotoXY(145, 20); cout << char(217);
	gotoXY(50, 20); cout << char(192);

	gotoXY(53, 1); cout << " ID ";
	gotoXY(53 + 15, 1); cout << "LOAI";
	gotoXY(53 + 15 + 17, 1); cout << "TEN";
	gotoXY(53 + 15 + 15 + 17, 1); cout << "DON VI";
	gotoXY(53 + 15 + 15 + 15 + 17 , 1); cout << "SO LUONG";
	gotoXY(53 + 15 + 15 + 15 + 15 + 17, 1); cout << "DON GIA";
	
}
void clearSpaceBehindFunc() {
	for (int i = 4; i < 20; i++) {
		SetColor(64);
		gotoXY(i, 10);
		cout << char(219);
	}
	}
void addNewItem() {
	food f2;
	clearSpaceBehindFunc();
	int x; cin >> x;
	getchar();
}

void startFunction() {
	int ok = 1;
	int choose;
	do {
		SetColor(15);
		gotoXY(4, 2); cout << " 1. Them vat pham ";
		gotoXY(4, 3); cout << " 2. Sua vat pham ";
		gotoXY(4, 4); cout << " 3. Xoa vat pham ";
		gotoXY(4, 5); cout << " 4. Tim kiem vat pham";
		gotoXY(4, 6); cout << " 5. Xem trang du lieu";
		gotoXY(4, 8); cout << " 0. Ve trang chu";
		gotoXY(4, 10); cout << "Chon chuc nang" << char(175); cin >> choose;
			switch(choose) {
			case 1: {
				addNewItem();
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
				break;
			}
			case 0: {
				ok = 0;
				break;
			}
			}
	} while (ok);
	
}
void manageFood() {
	system("cls");
	
	drawFrame();
	startFunction();
	//for(int i = 0; i < countFood ;i++)
	//gotoXY(0, 0); cout << L1;

	readFoodData();
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
	int a;
	cin >> a;
}