#include <iostream>
using namespace std;
#include "CTDL.h"
#include <string>


string bookTablePre::toString() {
	return this->id +","+this->namePerson + "," + this->sdt + "," + this->timeBook + "," + this->day
		+ "," + this->table + "," + to_string(this->phuthu) + "," + this->note;
}

void bookTablePre::setAllInfo(string id,string name, string sdt,string time, string day, string table, int pt, string note) {
	this->namePerson = name;
	this->id = id;
	this->sdt = sdt;
	this->day = day;
	this->table = table;
	this->phuthu = pt;
	this->note = note;
	this->timeBook = time;
}
string bookTablePre::getInfo(string get) {
	if (get == "ten") return this->namePerson;
	else if (get == "sdt") return this->sdt;
	else if (get == "id") return this->id;
	else if (get == "thoigian") return this->timeBook;
	else if (get == "ngay") return this->day;
	else if (get == "ban") return this->table;
	else if (get == "phuthu") return to_string(this->phuthu);
	else if (get == "ghichu") return this->note;
	else return "null";
}

void bookTablePre::editData(string get, string value) {
	if (get == "ten")  this->namePerson = value;
	else if (get == "sdt") this->sdt = value;
	else if (get == "id") this->id = value;
	else if (get == "thoigian")  this->timeBook = value;
	else if (get == "ngay")  this->day = value;
	else if (get == "ban")  this->table = value;
	else if (get == "phuthu")  to_string(this->phuthu) = value;
	else if (get == "ghichu")  this->note = value;

}