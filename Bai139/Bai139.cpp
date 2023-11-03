#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void SapXep(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	SapXep(b, k, l);
	Xuat(b, k, l);
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
void SapXep(float a[][100], int m, int n)
{
	int dong = m;
	int cot = n;
	int p = 0;
	int i, j;

	int k = 1;
	while (k <= m * n)
	{
		for (i = p; i < cot; i++)
			a[p][i] = k++;
		for (i = p + 1; i < dong; i++)
			a[i][cot - 1] = k++;
		if (p != dong - 1)
		{
			for (i = cot - 2; i >= p; i--)
				a[dong - 1][i] = k++;
		}
		if (p != cot - 1)
		{
			for (i = dong - 2; i > p; i--)
				a[i][p] = k++;
		}
		p++; dong--; cot--;
	}
}
