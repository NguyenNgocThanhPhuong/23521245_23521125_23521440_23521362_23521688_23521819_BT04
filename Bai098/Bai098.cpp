#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatDong(float[][100], int, int, int);
float LonNhatCot(float[][100], int, int, int);
float LonNhatCheo1(float[][100], int, int, int, int);
float LonNhatCheo2(float[][100], int, int, int, int);
bool ktHoangHau(float[][100], int, int, int, int);
int DemHoangHau(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nSo luong gia tri 'Hoang Hau' trong ma tran: " << DemHoangHau(b, k, l);
	cout << "\n\n\nKet Thuc!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> n;
	cout << "Nhap vao so cot: ";
	cin >> m;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[][100], int m, int n)
{
	cout << endl;
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
float LonNhatCheo1(float a[][100], int m, int n, int d, int c)
{
	float lc = a[d][c];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((i - j == d - c) && a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

float LonNhatCheo2(float a[][100], int m, int n, int d, int c)
{
	float lc = a[d][c];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((i + j == d + c) && a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

bool ktHoangHau(float a[][100], int m, int n, int d, int c)
{
	float lnd = LonNhatDong(a, m, n, d);
	float lnc = LonNhatCot(a, m, n, c);
	float lnc1 = LonNhatCheo1(a, m, n, d, c);
	float lnc2 = LonNhatCheo2(a, m, n, d, c);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (lnd == a[d][c] && lnc == a[d][c] && lnc1 == a[d][c] && lnc2 == a[d][c])
				return true;
	return false;
}

int DemHoangHau(float a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktHoangHau(a, m, n, i, j) == 1)
				dem++;
	return dem;
}
