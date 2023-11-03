﻿﻿#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	int dd;
	cout << "\nDong liet ke gia tri chan: ";
	cin >> dd;
	LietKe(b, k, l, dd);

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

void LietKe(int a[][100], int m, int n, int d)
{
	cout << "Cac gia tri chan tren dong " << d << ": ";
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 == 0)
			cout << setw(10) << a[d][j];
}