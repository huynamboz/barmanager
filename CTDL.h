#pragma once
#include "dontedit.h"

class user {
	string username;
	string password;
public:
	user* next;
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
	user(string, string, string, string, string, string
		, string, string, string, string, string);
};

class ListUser : public user {
public:
	user* head;
	int count;
	ListUser();
	void addNewUser(user);
	void showAllData();
};
