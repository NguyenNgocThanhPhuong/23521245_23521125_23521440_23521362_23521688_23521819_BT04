#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktDongGiam(float[][100], int, int, int);
bool ktCotGiam(float[][100], int, int, int);
bool ktGiam(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	if (ktGiam(b, k, l))
		cout << "Ma tran giam dan theo dong va cot";
	else
		cout << "Ma tran khong giam dan theo dong va cot";
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

bool ktDongGiam(float a[][100], int m, int n, int d)
{
	for (int j = 0; j <= n - 2; j++)
		if (a[d][j] < a[d][j + 1])
			return false;
	return true;
}

bool ktCotGiam(float a[][100], int m, int n, int c)
{
	for (int i = 0; i <= m - 2; i++)
		if (a[i][c] < a[i + 1][c])
			return false;
	return true;
}

bool ktGiam(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDongGiam(a, m, n, i) == false)
			return false;

	for (int j = 0; j < n; j++)
		if (ktCotGiam(a, m, n, j) == false)
			return false;
	return true;
}
