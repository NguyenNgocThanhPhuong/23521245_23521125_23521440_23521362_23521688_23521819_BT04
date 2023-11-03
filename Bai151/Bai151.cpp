#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongCot(float[][100], int, int);
void ThemDong(float[][100], int&, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	ThemDong(b, k, l);

	cout << "\nMa tran moi:\n";
	Xuat(b, k, l);

	cout << "\n\n\nKetthuc!!!";
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

float TongCot(float a[][100], int m, int n, int c)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		s += a[i][c];
	return s;
}

void ThemDong(float a[][100], int& m, int n)
{
	for (int j = 0; j < n; j++)
		a[m][j] = TongCot(a, m, n, j);
	m++;
}