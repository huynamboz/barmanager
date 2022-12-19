#include "Header.h"


using namespace std;


void user::setUsername(string u) {
	this->username = u;
}
void user::setPassword(string u) {
	this->password = u;
}
void user::setAccount(string user, string pass) {
	this->username = user;
	this->password = pass;
}
string user::Tostring() {
	return ID + "," + username + "," + password + "," + email + "," + name +","+gender
		+ "," + pNum + "," + bdate + "," + address + "," + permiss + "," + position;
}
string user::getUsername() {
	return this->username;
}
string user::getPassword() {
	return this->password;
}


void user::setAnotherInfo(string id, string mail, string name, string gender, string num, string date,
	string addr, string per, string pos) {
	this->ID = id;
	this->email = mail;
	this->name = name;
	this->gender = gender;
	this->pNum = num;
	this->bdate = date;
	this->address = addr;
	this->permiss = per;
	this->position = pos;
}

string user::getInfo(string whatGet) {
	
	if (whatGet == "id") return this->ID;
	else if (whatGet == "email") return this->email;
	else if (whatGet == "username") return this->username;
	else if (whatGet == "password") return this->password;
	else if (whatGet == "name") return this->name;
	else if (whatGet == "gender") return this->gender;
	else if (whatGet == "pNum") return this->pNum;
	else if (whatGet == "bdate") return this->bdate;
	else if (whatGet == "address") return this->address;
	else if (whatGet == "permiss") return this->permiss;
	else if (whatGet == "position") return this->position;
	else return "NULL";
}
void user::setInfo(string whatSet, string val) {

	if (whatSet == "id")  this->ID = val;
	else if (whatSet == "email")  this->email = val;
	else if (whatSet == "username")  this->username = val;
	else if (whatSet == "password")  this->password = val;
	else if (whatSet == "name")  this->name = val;
	else if (whatSet == "gender")  this->gender = val;
	else if (whatSet == "pNum")  this->pNum = val;
	else if (whatSet == "bdate")  this->bdate = val;
	else if (whatSet == "address")  this->address = val;
	else if (whatSet == "permiss")  this->permiss = val;
	else if (whatSet == "position")  this->position = val;
}