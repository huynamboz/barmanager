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
	
public:
	food* next;
	string ID;
	string category;
	string name;
	string type;
	int qty;
	int cost;
	string ToString();
	food() {};
	food(string, string, string, string, int, int);
	food(food &);
	friend istream& operator >>(istream&, food&);
};

class ListFood :public food{
public:
	food* head;
	ListFood();
	friend ostream& operator <<(ostream&, const ListFood&);
	void addNewFood( food&);
};