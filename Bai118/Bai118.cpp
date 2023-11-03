#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatDong(float[][100], int, int, int);
float LonNhatCot(float[][100], int, int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	float c[100][100];
	int p, q;
	XayDung(b, k, l, c, p, q);

	cout << "Ma tran moi :\n";
	Xuat(c, p, q);
	cout << "\n\n\nKetthuc!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "\nNhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);;
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

float LonNhatDong(float a[][100], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
		if (lc < a[d][j])
			lc = a[d][j];
	return lc;
}

float LonNhatCot(float a[][100], int m, int n, int c)
{
	float lc = a[0][c];
	for (int i = 0; i < m; i++)
		if (lc < a[i][c])
			lc = a[i][c];
	return lc;
}

void XayDung(float a[][100], int m, int n, float c[][100], int& d, int& e)
{
	d = m;
	e = n;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < e; j++)
		{
			float lnd = LonNhatDong(a, m, n, i);
			float lnc = LonNhatCot(a, m, n, j);
			if (lnd < lnc)
				c[i][j] = lnc;
			else
				c[i][j] = lnd;
		}
}
