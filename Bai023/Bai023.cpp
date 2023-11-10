#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int KtCucTieu(float[][100], int, int, int, int);
void XuatCucTieu(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	XuatCucTieu(b, k, l);
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

int KtCucTieu(float a[][100], int m, int n, int d, int c)
{
	int flag = 1;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if ((d + di >= 0 && d + di < m) &&
				(c + dj >= 0 && c + dj < n) &&
				!(di == 0 && dj == 0))
				if (a[d + di][c + dj] <= a[d][c])
					flag = 0;
	return flag;
}

void XuatCucTieu(float a[][100], int m, int n)
{
	cout << "Cac gia tri cuc tieu: ";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (KtCucTieu(a, m, n, i, j))
				cout << fixed << setw(10) << setprecision(3) << a[i][j];
}