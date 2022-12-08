#pragma once
#include "dontedit.h"

class person {
protected:
	string ID;
	string email;
	string name;//ten
	string gender;// gioi tinh
	string pNum; //so dien thoai
	string bdate; // ngay sinh nhat
	string address;//dia chi
};

class user : public person{
	string username;
	string password;
	string permiss;//quyen truy cap
	string position;//vi tri nhan vien
public:
	string Tostring();
	void setUsername(string);
	void setPassword(string);
	void setAccount(string, string);
	string getUsername();
	string getPassword();
	void setAnotherInfo(string, string, string, string, string,
		string, string, string, string);
	string getInfo(string); // lay ra dữ liệu muốn lấy
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

	void setAllInfo(string, string, string, string, int, int);
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
	void editData(string, ListFood , int);
	void find(string );
	void setNewQtyFromOrder(string ,int);
};


//---------quan ly nhan vien----------//
class bookTablePre {
private:
	string id;
	string namePerson;
	string sdt;
	string timeBook;
	string day;
	string table;
	int phuthu;
	string note;
public:
	string toString();
	void setAllInfo(string,string, string ,string, string, string, int, string);
	string getInfo(string);
	void editData(string,string);
};


class barCalender {
private:
	string date;
	string detail;
	int phuthu;
public:
	string getInfo(string);
	void setAnotherInfo(string, string, int);
};

class doanhthu {
private:
	string ID;
	string name;
	int soluong;
	int tong;
	int total;
public:
	string getInfo(string);
};