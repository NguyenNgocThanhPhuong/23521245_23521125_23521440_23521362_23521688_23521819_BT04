#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatDong(float[][100], int, int, int);
float LonNhatCot(float[][100], int, int, int);
float NhoNhatDong(float[][100], int, int, int);
float NhoNhatCot(float[][100], int, int, int);
bool ktYenNgua(float[][100], int, int, int&, int&);
int DemYenNgua(float[][100], int, int);


int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\nSo luong Yen Ngua: " << DemYenNgua(b, k, l);
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

float LonNhatDong(float a[][100], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
		if (a[d][j] > lc)
			lc = a[d][j];
	return lc;
}

float NhoNhatDong(float a[][100], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
		if (a[d][j] < lc)
			lc = a[d][j];
	return lc;
}

float LonNhatCot(float a[][100], int m, int n, int c)
{
	float lc = a[0][c];
	for (int j = 0; j < n; j++)
		if (a[j][c] > lc)
			lc = a[j][c];
	return lc;
}

float NhoNhatCot(float a[][100], int m, int n, int c)
{
	float lc = a[0][c];
	for (int j = 0; j < n; j++)
		if (a[j][c] < lc)
			lc = a[j][c];
	return lc;
}

bool ktYenNgua(float a[][100], int m, int n, int& i, int& j)
{
	if ((a[i][j] == LonNhatDong(a, m, n, i) && a[i][j] == NhoNhatCot(a, m, n, j)) || (a[i][j] == NhoNhatDong(a, m, n, i) && a[i][j] == LonNhatCot(a, m, n, j)))
		return true;
	return false;
}

int DemYenNgua(float a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktYenNgua(a, m, n, i, j))
				dem = dem + 1;
	return dem;
}
