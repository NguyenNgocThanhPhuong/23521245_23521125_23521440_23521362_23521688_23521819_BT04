#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int ChanDau(int[][100], int, int);
int ChanLonNhat(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nGia tri chan lon nhat: " << ChanLonNhat(b, k, l);
	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "\nNhap so dong : ";
	cin >> m;
	cout << "\nNhap so cot : ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

int ChanDau(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				return a[i][j];
}

int ChanLonNhat(int a[][100], int m, int n)
{
	int lc = ChanDau(a, m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > lc && a[i][j] % 2 == 0)
				lc = a[i][j];
	return lc;
}