
#include "dontedit.h"
#include "Header.h"

using namespace std;

ListFood L3;
void readFoodData_now() {
	ListFood L2;
	int k = 0;
	ifstream infile;
	infile.open("ordering.txt", ios_base::in);
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
		f1.setQty(qty);
		f1.setCost(cost);
		//gotoXY(0, k+20); cout << id;
		//gotoXY(0, k); cout << f1.ToString();

		L3.addNewFood(f1);

		k++;
		L3.count = k;
	};
	
	infile.close();

}
int max_numberTable = 20;



void order_main() {
	system("cls");
	

}
