#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void BienMaTran(float[][100], int, int, float[], int&);
void HoanVi(float&, float&);
void SapXep(float[], int);
void DuongBienTang(float[][100], int, int, float[], int);

int main()
{
	float b[100][100];
	float c[100];
	int k, l, g;

	cout << "\nNhap ma tran " << endl;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
	Xuat(b, k, l);

	BienMaTran(b, k, l, c, g);
	SapXep(c, g);
	DuongBienTang(b, k, l, c, g);

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

void HoanVi(float& a, float& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void BienMaTran(float a[][100], int m, int n, float b[], int& kk)
{
	int h = 0;
	for (int j = 0; j < n - 1; j++)
	{
		b[h] = a[0][j];
		h++;
	}
	for (int i = 0; i < m - 1; i++)
	{
		b[h] = a[i][n - 1];
		h++;
	}
	for (int j = n - 1; j >= 1; j--)
	{
		b[h] = a[m - 1][j];
		h++;
	}
	for (int i = m - 1; i > 0; i--)
	{
		b[h] = a[i][0];
		h++;
	}
	kk = h;
}

void SapXep(float b[], int kk)
{
	for (int i = 0; i < kk - 1; i++)
		for (int j = i + 1; j < kk; j++)
			if ((b[i] > b[j]) && (b[i] > 0 && b[j] > 0))
				HoanVi(b[i], b[j]);
}

void DuongBienTang(float a[][100], int m, int n, float b[], int kk)
{
	int h = 0;
	for (int j = 0; j < n - 1; j++)
	{
		a[0][j] = b[h];
		h++;
	}
	for (int i = 0; i < m - 1; i++)
	{
		a[i][n - 1] = b[h];
		h++;
	}
	for (int j = n - 1; j >= 1; j--)
	{
		a[m - 1][j] = b[h];
		h++;
	}
	for (int i = m - 1; i > 0; i--)
	{
		a[i][0] = b[h];
		h++;
	}
}
