#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongDong(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	int d;
	cout << "\nDong tinh tong cac gia tri duong: ";
	cin >> d;

	cout << "\nTong cac gia tri duong cua dong " << d << " la: " << TongDong(b, k, l, d);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

float TongDong(float a[][100], int m, int n, int d)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		if (a[d][j] > 0)
			s += a[d][j];
	return s;
}