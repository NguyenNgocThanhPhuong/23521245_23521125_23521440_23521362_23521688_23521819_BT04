#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void XuatMaTranB(int[][100], int, int);
void XayDung(float[][100], int, int, int[][100], int&, int&);
int DemLanCan(float[][100], int, int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran a:\n";
	Xuat(b, k, l);

	int c[100][100];
	int x, y;

	XayDung(b, k, l, c, x, y);

	cout << "Ma tran b: \n";
	XuatMaTranB(c, k, l);

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

void XuatMaTranB(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

int DemLanCan(float a[][100], int m, int n, int d, int c)
{
	int dem = 0;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && !(di == 0 && dj == 0))
				if (a[d + di][c + dj] > 0)
					dem++;
	return dem;
}

void XayDung(float a[][100], int m, int n, int b[][100], int& k, int& l)
{
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			b[i][j] = DemLanCan(a, m, n, i, j);
}
