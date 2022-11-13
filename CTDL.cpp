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
	out << " cac san pham la ";
	food* tmp = f.head;
	while (tmp != NULL) {
		out << tmp->ID << tmp->category <<
			tmp->name << " " << tmp->type << " " << tmp->qty << " " << tmp->cost;
		out << endl;
		tmp = tmp->next;
	}
	out << "<<<<";

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
		newFood->next = head;
		head = newFood;
	}
}

