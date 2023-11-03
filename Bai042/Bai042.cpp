#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDang2m(int);
int TongCot(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMang ban dau: \n";
	Xuat(b, k, l);

	int c;
	cout << "\nCot can tinh tong gia tri co dang 2^m: ";
	cin >> c;

	cout << "\nTong gia tri co dang 2^m tren cot" << c << ": " << TongCot(b, k, l, c);

	cout << "\n\n\nKet thuc.";
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
			a[i][j] = rand() / (RAND_MAX / 200) - 100;
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

bool ktDang2m(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 2)
		if (t % 2 != 0)
			flag = false;
	return flag;
}

int TongCot(int a[][100], int m, int n, int c)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		if (ktDang2m(a[i][c]) == true)
			s = s + a[i][c];
	return s;
}