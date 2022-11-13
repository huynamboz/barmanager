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
user::user(string id, string username, string pass,string name, string email,
	string gender, string phone, string birthday, string adds,
	string perm, string pos) {
	this->ID = id;
	this->email = email;
	this->password = pass;
	this->name = name;
	this->gender = gender;
	this->pNum = phone;
	this->bdate = birthday;
	this->address = adds;
	this->permiss = perm;
	this->position = pos;
	this->next = NULL;
}
void ListUser::addNewUser(user p) {
	count++;
	user* newUser = new user(p);
	if (head == NULL) {
		head = newUser;
	}
	else {
		newUser->next = head;
		head = newUser;
	}
}
void ListUser::showAllData() {

}