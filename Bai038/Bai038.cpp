#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDang5m(int);
int Tong(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	int dd;
	cout << "\nNhap dong: ";
	cin >> dd;

	cout << "\nTong cac gia tri co dang 5^m cua dong " << dd << " la: " << Tong(b, k, l, dd);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

bool ktDang5m(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 5)
		if (t % 5 != 0)
			flag = false;
	return flag;
}

int Tong(int a[][100], int m, int n, int d)
{
	int s = 0;
	for (int j = 0; j < n; j++)
		if (ktDang5m(a[d][j]))
			s = s + a[d][j];
	return s;
}