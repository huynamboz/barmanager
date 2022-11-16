#include "Header.h"
using namespace std;
void user::setUsername(string u) {
	this->username = u;
}
void user::setPassword(string u) {
	this->password = u;
}
string user::Tostring() {
	return ID + "," + username + "," + password + "," + email + "," + gender
		+ "," + pNum + "," + bdate + "," + address + "," + permiss + "," + position;
}
string user::getUsername() {
	return this->username;
}
string user::getPassword() {
	return this->password;
}





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
	getline(cin, cate); f2.category = cate;
	clearSpaceBehindFunc();


	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap ten " << char(175) << " ";
	getline(cin, name); f2.name = name;
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap don vi " << char(175) << " ";
	getline(cin, type); f2.type = type;
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap so luong " << char(175) << " ";
	cin >> qty; f2.qty = qty;
	clearSpaceBehindFunc();

	/*--nhap ten--*/
	gotoXY(4, 10); cout << "Nhap don gia " << char(175) << " ";
	cin >> cost; f2.cost = cost;
	clearSpaceBehindFunc();
	return f2;
}
void ListFood::editNode() {
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