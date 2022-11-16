# barmanager
<h1>Đồ án môn học kỳ 1 năm 2</h1>
</br> OOP - Linkedlist single list
</br>

```cpp
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
	friend ostream& operator <<(ostream&, food&);
};

class ListFood :public food{
public:
	int count;
	food* head;
	ListFood();
	food& operator[](const int);
	friend ostream& operator <<(ostream&, const ListFood&);
	void addNewFood( food&);
	void showPage(int);
};
```

</br> Using 

```cpp
int main(){
List L1;
food f1;

L1.addNewFood(f1); // create node and add to linkedlist
}
```

</br> Have good day :))) 
