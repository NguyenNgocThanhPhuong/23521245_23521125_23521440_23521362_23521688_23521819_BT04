#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktCucDai(float[][100], int, int, int, int);
bool ktCucTieu(float[][100], int, int, int, int);
float TongCucTri(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nTong cac phan tu cuc tri trong ma tran:" << TongCucTri(b, k, l);

	cout << "\n\n\nKet thuc!!!";
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

bool ktCucDai(float a[][100], int m, int n, int c, int d)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (c + i >= 0 && c + i < m && d + j >= 0 && d + j < n && !(i == 0 && j == 0))
				if (a[c][d] < a[c + i][d + j])
					return false;
	return true;
}

bool ktCucTieu(float a[][100], int m, int n, int c, int d)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (c + i >= 0 && c + i < m && d + j >= 0 && d + j < n && !(i == 0 && j == 0))
				if (a[c][d] > a[c + i][d + j])
					return false;
	return true;
}

float TongCucTri(float a[][100], int m, int n)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j) || ktCucTieu(a, m, n, i, j))
				s += a[i][j];
	return s;
}