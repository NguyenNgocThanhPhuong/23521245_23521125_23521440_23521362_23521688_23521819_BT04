#include <iostream>
#include <iomanip>

using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanViDong(float[][100], int, int, int, int);
float TongDong(float[][100], int, int, int);
void SapXep(float[][100], int, int);


int main()
{
	float b[100][100];
	int k, l, c, d;

	Nhap(b, k, l);
	cout << "\nMa tran ban dau:\n";

	Xuat(b, k, l);
	cout << "\nMa tran sau khi sap xep:\n";
	SapXep(b, k, l);
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

void HoanViDong(float a[][100], int m, int n, int d1, int d2)
{
	for (int j = 0; j < n; j++)
		swap(a[d1][j], a[d2][j]);
}

float TongDong(float a[][100], int m, int n, int d)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s = s + a[d][j];
	return s;
}

void SapXep(float a[][100], int m, int n)
{
	for (int i = 0; i <= m - 2; i++)
		for (int j = i + 1; j <= m - 1; j++)
			if (TongDong(a, m, n, i) > TongDong(a, m, n, j))
				HoanViDong(a, m, n, i, j);
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}
