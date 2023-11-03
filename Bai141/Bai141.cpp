#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void XoaDong(float[][100], int&, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	int d;
	cout << "Nhap dong can xoa: ";
	cin >> d;

	XoaDong(b, k, l, d);
	cout << "Sau khi xoa dong " << d << ": \n";
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
			a[i][j] = rand() / (float)(RAND_MAX / 200) - 100;
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

void XoaDong(float a[][100], int& m, int n, int d)
{
	for (int j = 0; j < n; j++)
		for (int i = d; i <= n - 2; i++)
			a[i][j] = a[i + 1][j];
	m--;
}