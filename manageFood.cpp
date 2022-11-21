#include "dontedit.h"
#include "Header.h"
using namespace std;
ListFood L1;
int countFood = 0;
int allPage;
int pageNow = 1;



void readFoodData() {
	ListFood L2;
	int k = 0;
	ifstream infile;
	infile.open("foodData.txt", ios_base::in);
	/*infile.ignore();
	infile.ignore();*/

	string id = "", cate, name, type; int qty, cost;
	while (infile.eof() != true) {
		food f1;

		
		getline(infile, id, ',');
		getline(infile, cate, ',');
		getline(infile, name, ',');
		getline(infile, type, ',');
		infile >> qty;
		infile.ignore();
		infile >> cost;
		infile.ignore();

		f1.setID(id);
		f1.setCategory(cate);
		f1.setName(name);
		f1.setType(type);
		f1.setQty(qty) ;
		f1.setCost(cost);
		//gotoXY(0, k+20); cout << id;
		//gotoXY(0, k); cout << f1.ToString();

		L2.addNewFood(f1);
		
		k++;
		countFood = k;
		L2.count = countFood;
	};
	if (countFood % 7 == 0) allPage = countFood / 7;
	else allPage = countFood / 7 + 1;
	L1 = L2;
	infile.close();

}

void writeFoodData() {
	fstream writedata;
	writedata.open("foodData.txt", ios::out);
	food* tmp = L1.head; int i = 0;
	while (tmp != NULL) {
		i++;
			writedata << tmp->ToString();
			//cout << tmp->ToString()<<endl;
			tmp = tmp->next;
		//if (writedata.eof() != true) writedata << endl;
		if (i != countFood ) writedata << endl;
	}
	writedata.close();
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
	gotoXY(53 + 15 + 15 + 22, 1); cout << "DON VI";
	gotoXY(53 + 15 + 15 + 16 + 17 , 1); cout << "SO LUONG";
	gotoXY(53 + 15 + 15 + 15 + 15 + 17, 1); cout << "DON GIA";
	

}
void clearLoadData() {
	SetColor(0);
	for (int x = 51; x < 145; x++) {
		for (int y = 2; y < 19; y++) {
			gotoXY(x, y); cout << char(219);
		}
	}
	SetColor(127);
}

void clearSpaceBehindFunc() {
	for (int i = 4; i < 50; i++) {
		SetColor(64);
		gotoXY(i, 10);
		cout << char(219);
	}
	SetColor(127);

	}


void loadData() {
	cout << L1;
}

void addNewItem() {
	
	cin.ignore();
	clearSpaceBehindFunc();
	L1.setData();
	countFood++;
	writeFoodData();
	readFoodData();
	clearLoadData();
	gotoXY(0, 0); L1.showPage(allPage);
	//loadData();
}

void viewPageData() {
	clearSpaceBehindFunc();
	gotoXY(4, 10); cout << "Nhap trang muon xem :";
	cin >> pageNow;
	if (pageNow <= allPage) {
		clearLoadData();
		L1.showPage(pageNow);
	}
	
}

void clearMenu() {
	for (int i = 2; i < 9; i++) {
		SetColor(64);
		gotoXY(4, i);
		for(int j = 0;j<30;j++)cout << char(219);
	}
	SetColor(127);
}
void deleteFood() {
	clearSpaceBehindFunc();
	string data;
	gotoXY(4, 10); cout << "Nhap ten hoac ID muon xoa :";
	cin.ignore();
	getline(cin, data);


	L1.deleteNode(data);
	clearLoadData();
	countFood--;
	L1.count--;
	writeFoodData();
	readFoodData();
	L1.showPage(1);
}


void editData() {
	clearSpaceBehindFunc();
	int ok = 1;
	do {
		clearSpaceBehindFunc();
		clearMenu();
		gotoXY(4, 2); cout << " 1. Sua loai vat pham";
		gotoXY(4, 3); cout << " 2. Sua ten vat pham";
		gotoXY(4, 4); cout << " 3. Sua don vi ";
		gotoXY(4, 5); cout << " 4. Sua so luong";
		gotoXY(4, 6); cout << " 5. Sua gia tien";
		gotoXY(4, 8); cout << " 0. Thoat"; int choose;
		gotoXY(4, 10); cout << "Chon chuc nang" << char(175) << " "; cin >> choose;
		switch (choose) {
		case 1: {
			cin.ignore();
			string id;
			gotoXY(4, 10); cout << "Nhap id can sua " << char(175) << " ";
			getline(cin, id);
			L1.editData(id, L1, 1);
			readFoodData();
			L1.showPage(pageNow);
			break;
		}
		case 2: {
			cin.ignore();
			string id;
			gotoXY(4, 10); cout << "Nhap id can sua " << char(175) << " ";
			getline(cin, id);
			L1.editData(id, L1, 2);
			readFoodData();
			L1.showPage(pageNow);
			break;
		}
		case 3: {
			cin.ignore();
			string id;
			gotoXY(4, 10); cout << "Nhap id can sua " << char(175) << " ";
			getline(cin, id);
			L1.editData(id, L1, 3);
			readFoodData();
			L1.showPage(pageNow);
			break;
		}
		case 4: {
			cin.ignore();
			string id;
			gotoXY(4, 10); cout << "Nhap id can sua " << char(175) << " ";
			getline(cin, id);
			L1.editData(id, L1, 4);
			readFoodData();
			L1.showPage(pageNow);
			break;
		}
		case 5: {
			cin.ignore();
			string id;
			gotoXY(4, 10); cout << "Nhap id can sua " << char(175) << " ";
			getline(cin, id);
			L1.editData(id, L1, 5);
			readFoodData();
			L1.showPage(pageNow);
			break;
		}
		case 0: {
			ok = 0;
			break;
		}
		}
	} while (ok);
}

void findFood() {
	clearSpaceBehindFunc();
	cin.ignore();
	string str;
	gotoXY(4, 10); cout << "Nhap id hoac ten vat pham can tim ";
	gotoXY(4, 11); cout << char(175) << " "; getline(cin, str);
	for (int i = 4; i < 50; i++) {
		SetColor(64);
		gotoXY(i, 11);
		cout << char(219);
		gotoXY(i, 15);
		cout << char(219);
		gotoXY(i, 16);
		cout << char(219);
		gotoXY(i, 17);
		cout << char(219);
	}
	SetColor(127);
	L1.find(str);
}

void startFunction() {
	int ok = 1;
	int choose;
	do {
		clearSpaceBehindFunc();
		SetColor(15);
		gotoXY(4, 2); cout << " 1. Them vat pham ";
		gotoXY(4, 3); cout << " 2. Sua vat pham ";
		gotoXY(4, 4); cout << " 3. Xoa vat pham ";
		gotoXY(4, 5); cout << " 4. Tim kiem vat pham";
		gotoXY(4, 6); cout << " 5. Xem trang du lieu";
		gotoXY(4, 8); cout << " 0. Ve trang chu";
		gotoXY(4, 10); cout << "Chon chuc nang" << char(175)<<" "; cin >> choose;
			switch(choose) {
			case 1: {
				addNewItem();
				break;
			}
			case 2: {
				editData();
				readFoodData();
				break;
			}
			case 3: {
				deleteFood();
				break;
			}
			case 4: {
				findFood();
				break;
			}
			case 5: {
				viewPageData();
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
	
	readFoodData();
	L1.showPage(pageNow);
	//loadData();
	drawFrame();
	startFunction();
	system("cls");
	//for(int i = 0; i < countFood ;i++)
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