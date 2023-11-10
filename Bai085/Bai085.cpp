#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int ChinhPhuongDau(int[][100], int, int);
int ChinhPhuongLonNhat(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nSo chinh phuong lon nhat trong ma tran: " << ChinhPhuongDau(b, k, l);
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

bool ktChinhPhuong(int x)
{
	for (int i = 1; i <= x; i++)
		if (i * i == x)
			return true;
	return false;
}

int ChinhPhuongDau(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]))
				return a[i][j];
	return 0;
}

int ChinhPhuongLonNhat(int a[][100], int m, int n)
{
	int lc = ChinhPhuongDau(a, m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]) && a[i][j] > lc)
				lc = a[i][j];
	return lc;
}