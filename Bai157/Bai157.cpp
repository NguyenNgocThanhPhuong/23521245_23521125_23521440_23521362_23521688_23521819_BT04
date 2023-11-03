#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DichTraiDong(float[][100], int, int, int);
void DichTrai(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nsap xep day dich trai: \n";
	DichTrai(b, k, l);
	Xuat(b, k, l);

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
			cout << fixed << setw(10) << setprecision(2) << a[i][j];
		cout << endl;
	}
}

void DichTraiDong(float a[][100], int m, int n, int d)
{
	float temp = a[d][0];
	for (int j = 0; j < n - 1; j++)
		a[d][j] = a[d][j + 1];
	a[d][n - 1] = temp;
}

void DichTrai(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		DichTraiDong(a, m, n, i);
}