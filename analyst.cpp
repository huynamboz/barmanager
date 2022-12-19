
#include "dontedit.h"
#include "Header.h"
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
	gotoXY(XX, YY+=5);

}
void analyst_action() {
	system("cls");
	show_data_analyst();
	system("pause");
	system("cls");
}