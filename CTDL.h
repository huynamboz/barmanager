#pragma once
#include "dontedit.h"

class user {
	string username;
	string password;
public:

	string ID;
	string email;
	string name;
	string gender;
	string pNum;
	string bdate;
	string address;
	string permiss;
	string position;

	string Tostring();
	void setUsername(string);
	void setPassword(string);

	string getUsername();
	string getPassword();
	
};

class food {
private:
	string ID;
	string category;
	string name;
	string type;
	int qty;
	int cost;
public:
	food* next;
	
	string getID() { return this->ID; };
	string getCategory() { return this->category; };
	string getName() { return this->name; };
	string getType() { return this->type; };
	int getQty() { return this->qty; };
	int getCost() { return this->cost; };

	void setID(string);
	void setCategory(string) ;
	void setName(string) ;
	void setType(string);
	void setQty(int);
	void setCost(int);

	string ToString();
	food() {};
	food(string, string, string, string, int, int);
	food(food &);
	friend istream& operator >>(istream&, food&);
	friend ostream& operator <<(ostream&,const food&);
	friend class ListFood;
};

class ListFood {
public:
	int count;
	food* head;
	ListFood();
	food& operator[](const int);
	friend ostream& operator <<(ostream&, const ListFood&);
	void addNewFood( food&);
	food& setData();
	void showPage(int);
	void deleteNode(string);
	void editNode();
};