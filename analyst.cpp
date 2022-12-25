
#include "dontedit.h"
#include "Header.h"

#pragma warning(disable : 4996)

time_t Time = time(NULL);
struct tm* Time1 = localtime(&Time);

doanhthu ListItem[100];
int slItem = 0;
void read_doanhthu() {
	int k = 0;
	ifstream infile;
	infile.open("doanhthu.txt", ios_base::in);
	/*infile.ignore();
	infile.ignore();*/

	string id = "", name; int qty, cost;
	while (infile.eof() != true) {
		getline(infile, id, ',');
		getline(infile, name, ',');
		infile >> qty;
		infile.ignore();
		infile >> cost;
		infile.ignore();
		ListItem[k].setAllInfo(id, name, qty, cost);
		k++;
		slItem = k;
	};

	infile.close();
}

void swap(doanhthu&a, doanhthu&b){
	doanhthu tmp = a;
	a = b;
	b = tmp;
}
int partition(doanhthu arr[], int low, int high)
{
	int pivot = stoi(arr[high].getInfo("sl"));    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && stoi(arr[left].getInfo("sl")) > pivot) left++; // Tìm phần tử >= arr[pivot]
		while (right >= left && stoi(arr[right].getInfo("sl")) < pivot) right--; // Tìm phần tử <= arr[pivot]
		if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
		swap(arr[left], arr[right]); // Nếu chưa xong, đổi chỗ.
		left++; // Vì left hiện tại đã xét, nên cần tăng
		right--; // Vì right hiện tại đã xét, nên cần giảm
	}
	swap(arr[left], arr[high]);
	return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quickSort(doanhthu arr[], int low, int high)
{
	if (low < high)
	{
		/* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
		 và là phần tử chia mảng làm 2 mảng con trái & phải */
		int pi = partition(arr, low, high);

		// Gọi đệ quy sắp xếp 2 mảng con trái và phải
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void show_data_analyst() {
	SetColor(127);
	read_doanhthu();
	reinput:
	int x = 45, y = 1;
	gotoXY(x++, y++); cout << "          DANH SACH VAT PHAM BAN CHAY NHAT";
	x++, y++;
	SetColor(78);
	gotoXY(x, y); cout << "ID";
	gotoXY(x + 10, y); cout << "TEN";
	gotoXY(x + 10 + 20, y); cout << "SO LUONG";
	gotoXY(x + 10 + 20 + 20, y); cout << "TONG";
	SetColor(63);
	int sum = 0;
	int XX = x, YY = y+2;
	quickSort(ListItem, 0, slItem-1);
	for (int i = 0; i < slItem; i++) {
		gotoXY(XX, YY);cout << ListItem[i].getInfo("id");
		gotoXY(XX + 10, YY); cout << ListItem[i].getInfo("ten");
		gotoXY(XX + 10 + 20, YY); cout << ListItem[i].getInfo("sl");
		gotoXY(XX + 10 + 20 + 20, YY); cout << ListItem[i].getInfo("tong");
		sum += stoi(ListItem[i].getInfo("tong"));
		YY += 2;
	}
	gotoXY(XX, YY); cout << "--------------------------";
	gotoXY(XX, YY+=2); cout << "Tong doanh thu : " << sum <<"d";
	string choose = "";
	gotoXY(XX, YY += 1); cout << "Go \"1\" de tong ket thang / \"2\" de xem doanh thu tung thang / \"0\" de thoat :";
	cin >> choose;
	if (choose == "1") {
		string cfm = "";
		gotoXY(XX, YY += 1); cout << "Ban chac chan muon tong ket doanh thu thang nay chua? (y/n)";
		cin >> cfm;
		if (cfm == "y") {
			string file="";
			int month = Time1->tm_mon + 1;
			file += "month_" + to_string(month) +".txt";

			fstream writedata;
			writedata.open(file, ios::out);
			for (int i = 0; i < slItem; i++) {
				writedata << ListItem[i].toString();
				if (i != slItem - 1) writedata << endl;
			}
			writedata.close();
		}
		else {
			system("cls");
			goto reinput;
		}
		
	}
	else if(choose == "2") {
		string mon = "";
		gotoXY(XX, YY += 1); cout << "Nhap thang ban muon xem doanh thu :"; cin >> mon;

		string file = "";
		file += "month_" + mon + ".txt";
		int k = 0;
		ifstream infile;
		infile.open(file, ios_base::in);
		/*infile.ignore();
		infile.ignore();*/

		string id = "", name; int qty, cost;
		while (infile.eof() != true) {
			getline(infile, id, ',');
			getline(infile, name, ',');
			infile >> qty;
			infile.ignore();
			infile >> cost;
			infile.ignore();
			ListItem[k].setAllInfo(id, name, qty, cost);
			k++;
			slItem = k;
		};

		infile.close();
		system("cls");
		goto reinput;

	}
	gotoXY(XX, YY+=5);
	

}
void analyst_action() {
	system("cls");
	show_data_analyst();
	system("pause");
	system("cls");
}