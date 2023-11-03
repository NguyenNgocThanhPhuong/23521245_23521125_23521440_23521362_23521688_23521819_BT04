#include<iostream>
#include<iomanip>
#include <ctime>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int TongChinhPhuongBienAdv(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\nKet qua:" << TongChinhPhuongBienAdv(b, k, l);

	cout << "\n\n\nKet thuc!!!";
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

bool ktChinhPhuong(int n)
{
	bool flag = false;
	for (int i = 0; i <= n; i++)
		if (i * i == n)
			flag = true;
	return flag;
}

int TongChinhPhuongBienAdv(int a[][100], int m, int n)
{
	int s = 0;
	for (int j = 0; j <= n - 2; j++)
		if (ktChinhPhuong(a[0][j]) == true)
			s += a[0][j];
	for (int i = 0; i <= m - 2; i++)
		if (ktChinhPhuong(a[i][n - 1]) == true)
			s += a[i][n - 1];
	for (int j = n - 1; j >= 1; j--)
		if (ktChinhPhuong(a[m - 1][j]) == true)
			s += a[m - 1][j];
	for (int i = m - 1; i >= 1; i--)
		if (ktChinhPhuong(a[i][0]) == true)
			s += a[i][0];
	return s;
}