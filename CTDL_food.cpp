#include "Header.h"


using namespace std;






//----------------food------------//
void food::setID(string id){
	this->ID = id;
}
void food::setCategory(string cate){
	this->category = cate;
}
void food::setName(string name) {
	this->name = name;
}
void food::setType(string type) {
	this->type = type;
}
void food::setQty(int qty) {
	this->qty = qty;
}
void food::setCost(int cost) {
	this->cost = cost;
}

food& ListFood::operator[](const int index)
{
	gotoXY(0, 0); cout << "haha";
	return *head;
}

ostream& operator <<(ostream& out, const food& f) {
	
	SetColor(127);
	//gotoXY(0, 0); cout << "kookok";
		out << setw(7) << left << f.ID
			<< setw(21) << left << f.category
			<< setw(25) << left << f.name
			<< setw(13) << left << f.type
			<< setw(13) << left << f.qty
			<< setw(10) << left << f.cost;
	return out;
}
food::food(food &f) {
	this->ID = f.ID;
	this->category = f.category;
	this->name = f.name;
	this->type = f.type;
	this->qty = f.qty;
	this->cost = f.cost;
	this->next = NULL;
}
food::food(string id, string cate, string name, string type,
	int qty, int cost) {
	this->ID = id;
	this->category = cate;
	this->name = name;
	this->type = type;
	this->qty = qty;
	this->cost = cost;
	this->next = NULL;
}
ListFood::ListFood() {

}
ostream& operator <<(ostream& out, const ListFood& f) {
	food* tmp = f.head;
	SetColor(127);
	int x = 53, y = 2, i = 0;
	while (tmp != NULL) {
		i+=2;
		gotoXY(x, y + i ); 
		out << setw(7) << left << tmp->getID() 
			<< setw(21) << left << tmp->getCategory()
			<< setw(25)<< left << tmp->getName()
			<< setw(13) << left << tmp->getType()
			<< setw(13) << left << tmp->getQty()
			<< setw(10) << left << tmp->getCost();
		
		tmp = tmp->next;
	}

	return out;
}

istream& operator >> (istream& in, food& f) {
	cout << "nhap id"; getline(in,f.ID);
	cout << "nhap loai :"; getline(in, f.category);
	cout << "nhap ten "; getline(in, f.name);
	cout << "nhap so luong "; in >> f.qty;
	cout << "nhap gia "; in >> f.cost;
	in.ignore();
	return in;
}
string food::ToString() {
	return ID + "," + category + "," + name + "," + type + "," +
		std::to_string(qty) + "," + std::to_string(cost);
}

void ListFood::addNewFood( food& f) {
	food* newFood = new food(f);
	if (head == NULL) {
		head = newFood;
	}
	else {
		food* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newFood;
		tmp = head;
		head = tmp;
		
	}
}

void ListFood::showPage(int index) {
	food* tmp = this->head;
	int tempPage;
	SetColor(127);
	int x = 53, y = 2, nxt = 0; 

	if (count % 7 == 0) tempPage = count / 7;
	else tempPage = count / 7 + 1; 
	
	gotoXY(90, 19); cout << "TRANG [" << index << "]" << "/" << "[" << tempPage << "]";


	
	if (tempPage == index) {
		for (int i = 0; i < 7 * (index - 1); i++) {
			tmp = tmp->next;
		}
		for (int PageItem = 7 * (index - 1); PageItem < count; PageItem++) {
			nxt += 2;
			gotoXY(x, y + nxt);
			cout << setw(7) << left << tmp->ID
				<< setw(21) << left << tmp->category
				<< setw(25) << left << tmp->name
				<< setw(13) << left << tmp->type
				<< setw(13) << left << tmp->qty
				<< setw(10) << left << tmp->cost;

			tmp = tmp->next;
		}
	}
	else if(index < tempPage) {
		for (int i = 0; i < 7 * (index - 1); i++) {
			tmp = tmp->next;
		}
		for (int PageItem = 7 * (index - 1); PageItem < 7 * (index - 1) + 7; PageItem++) {
			nxt += 2;
			gotoXY(x, y + nxt);
			cout << setw(7) << left << tmp->ID
				<< setw(21) << left << tmp->category
				<< setw(25) << left << tmp->name
				<< setw(13) << left << tmp->type
				<< setw(13) << left << tmp->qty
				<< setw(10) << left << tmp->cost;

			tmp = tmp->next;
		}
	}
}
void ListFood::deleteNode(string data) {
	food* tmp = head;
	food* tmp2 = tmp;
	int i = 0;
	while (tmp != NULL) {
		if ((tmp->ID == data || tmp->name == data) && i ==0) {
			tmp = tmp->next;
			head = tmp;
			break;
		}
		else if ((tmp->ID == data || tmp->name == data) && i != 0) {
			tmp = tmp->next;
			tmp2->next = tmp;
			tmp2 = head;
			head = tmp2;
			break;
		}
		tmp2 = tmp;
		tmp = tmp->next;
		i++;
	}
}

food &ListFood::setData() {
	food f2;
	string cate, name, type; int qty, cost;

	f2.ID = "FK" + std::to_string(this->count + 1);
	/*--nhap loai--*/
	gotoXY(4, 10); cout << "Nhap loai " << char(175) << " ";
	getline(cin, cate); f2.setCategory(cate);
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap ten " << char(175) << " ";
	getline(cin, name); f2.setName(name);
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap don vi " << char(175) << " ";
	getline(cin, type); f2.setType(type);
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap so luong " << char(175) << " ";
	cin >> qty; f2.setQty(qty);
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap don gia " << char(175) << " ";
	cin >> cost; f2.setCost(cost);
	clearSpaceBehindFunc();
	this->addNewFood(f2);
	return f2;
}



void ListFood::editData(string id, ListFood  L, int func) {
	
	

	for (int i = 4; i < 50; i++) {
		SetColor(64);
		gotoXY(i, 11);
		cout << char(219);
	}
	SetColor(127);
	food* tmp = L.head;
	bool checkHave = false;
	while(tmp != NULL) {
		if (tmp->getID() == id) {
			checkHave = true;
		}
		tmp = tmp->next;
	}
	delete tmp;
	if (checkHave) {
		string cate, confirm; int qty, cost;
			clearSpaceBehindFunc();
			gotoXY(4, 10); 
			switch (func) {
			case 1: {
				cout << "Nhap loai moi :" << char(175) << " ";
				getline(cin, cate);
				break; }

			case 2: {
				cout << "Nhap ten moi :" << char(175) << " ";
				getline(cin, cate);
				break;
			}
			case 3: {
				cout << "Nhap don vi moi :" << char(175) << " ";
				getline(cin, cate);
				break;
			}
			case 4: {
				cout << "Nhap so luong moi :" << char(175) << " ";
				cin >> qty;
				break; }
			case 5: {
					cout << "Nhap don gia moi :" << char(175) << " ";
					cin >> cost;
					break; }
			}
			
			clearSpaceBehindFunc();
			gotoXY(4, 10); cout << "Ban chac chan chua(y/n) :" << char(175) << " ";
			cin >> confirm;
			if (confirm == "y") {
				food* tmp1 = L.head;
				while (tmp1 != NULL) {
					if (tmp1->getID() == id) {
						switch (func) {
						case 1: tmp1->setCategory(cate);
							break;
						case 2: tmp1->setName(cate);
							break;
						case 3 :tmp1->setType(cate);
							break;
						case 4 : tmp1->setQty(qty);
							break;
						case 5: tmp1->setCost(cost);
							break;
						}
						}
					tmp1 = tmp1->next;

					}

					tmp1 = L.head;
					L.head = tmp1;

					fstream writedata;
					writedata.open("foodData.txt", ios::out);
					int i = 0;
					while (tmp1 != NULL) {
						i++;
						writedata << tmp1->ToString();
						//cout << tmp->ToString()<<endl;
						tmp1 = tmp1->next;
						//if (writedata.eof() != true) writedata << endl;
						if (i != L.count) writedata << endl;
					}
					writedata.close();
				}
				

	}
	else {
		clearSpaceBehindFunc();
		SetColor(68);
		gotoXY(4, 11); cout << "Vat pham ban can sua khong co trong danh sach" << " ";
	}
}

void ListFood::find(string str) {
	
	food* tmp = this->head;
	while (tmp != NULL)
	{
		if (tmp->getID() == str || tmp->getName() == str) {
			gotoXY(4, 15); cout << "ID   :" << tmp->getID();
			gotoXY(4, 16); cout << "Loai :" << tmp->getCategory();
			gotoXY(4, 17); cout << "Ten  :" << tmp->getName();
			gotoXY(26, 15); cout << "Don vi   :" << tmp->getType();
			gotoXY(26, 16); cout << "So luong :" << tmp->getQty();
			gotoXY(26, 17); cout << "Don gia  :" << tmp->getCost();
			break;
		} // nếu tìm thấy index thì thoát khỏi vòng lặp
			 // chưa tìm thấy thì tiếp tục duyệt phần tử kết tiếp
		tmp = tmp->next;
	}
}
void ListFood::setNewQtyFromOrder(string str,int data) {
	food* tmp = this->head;
	while (tmp != NULL)
	{
		if (tmp->getID() == str || tmp->getName() == str) {
			tmp->setQty(data);
		}
		tmp = tmp->next;
	}
	tmp = head;
	head = tmp;

	fstream writedata;
	writedata.open("foodData.txt", ios::out);
	int i = 0;
	while (tmp != NULL) {
		i++;
		writedata << tmp->ToString();
		//cout << tmp->ToString()<<endl;
		tmp = tmp->next;
		//if (writedata.eof() != true) writedata << endl;
		if (i != this->count) writedata << endl;
	}
	writedata.close();
}