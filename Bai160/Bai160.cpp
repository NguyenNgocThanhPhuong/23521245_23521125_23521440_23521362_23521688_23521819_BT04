#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void BienMaTran(float[][100], int, int, float[], int);
void DichTrai(float[][100], int, int, float[], int);

int main()
{
	float b[100][100];
	float c[100];
	int k, l;
	int h = 0;

	cout << "\nNhap ma tran " << endl;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
	Xuat(b, k, l);

	BienMaTran(b, k, l, c, h);
	DichTrai(b, k, l, c, h);

	cout << "\nMa tran sau sap xep : " << endl;
	Xuat(b, k, l);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap so dong : ";
	cin >> m;
	cout << "\nNhap so cot : ";
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

void BienMaTran(float a[][100], int m, int n, float b[], int k)
{
	for (int j = 0; j < n; j++)
	{
		b[k] = a[0][j];
		k++;
	}
	for (int i = 1; i < m; i++)
	{
		b[k] = a[i][n - 1];
		k++;
	}
	for (int j = n - 2; j >= 0; j--)
	{
		b[k] = a[m - 1][j];
		k++;
	}
	for (int i = m - 2; i > 0; i--)
	{
		b[k] = a[i][0];
		k++;
	}
}

void DichTrai(float a[][100], int m, int n, float b[], int k)
{
	int h = 1;
	for (int j = 0; j < n; j++)
	{
		a[0][j] = b[h];
		h++;
	}
	for (int i = 1; i < m; i++)
	{
		a[i][n - 1] = b[h];
		h++;
	}
	for (int j = n - 2; j >= 0; j--)
	{
		a[m - 1][j] = b[h];
		h++;
	}
	for (int i = m - 2; i > 0; i--)
	{
		a[i][0] = b[h];
		h++;
	}
	a[1][0] = b[0];
}