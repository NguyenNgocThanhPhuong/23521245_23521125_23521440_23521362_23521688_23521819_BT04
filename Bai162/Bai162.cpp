#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xoay180(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	Xoay180(b, k, l);

	cout << "Ma tran moi:\n";
	Xuat(b, k, l);
	cout << "\n\n\nKetthuc!";
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
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
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

void Xoay180(float a[][100], int& m, int& n)
{
	float b[100][100];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = a[m - i - 1][n - j - 1];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}