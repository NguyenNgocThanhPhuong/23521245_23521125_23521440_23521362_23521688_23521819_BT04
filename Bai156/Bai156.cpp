#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DichLenCot(float[][100], int, int, int);
void DichLen(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nMa tran sau khi chuyen:\n";
	DichLen(b, k, l);
	Xuat(b, k, l);

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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

void DichLenCot(float a[][100], int m, int n, int c)
{
	float temp = a[0][c];
	for (int i = 0; i <= m - 2; i++)
		a[i][c] = a[i + 1][c];
	a[m - 1][c] = temp;
}

void DichLen(float a[][100], int m, int n)
{
	for (int j = 0; j < n; j++)
		DichLenCot(a, m, n, j);
}