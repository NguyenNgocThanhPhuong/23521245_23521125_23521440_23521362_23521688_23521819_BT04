#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemChuSo(int);
int DemCot(int[][100], int, int);
int DemLonNhat(int[][100], int, int);
void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	LietKe(b, k, l);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
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

int DemChuSo(int k)
{
	if (k == 0)
		return 1;
	int dem = 0;
	while (k != 0)
	{
		k /= 10;
		dem++;
	}
	return dem;
}

int DemCot(int a[][100], int m, int n, int c)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		s += DemChuSo(a[i][c]);
	return s;
}

int DemLonNhat(int a[][100], int m, int n)
{
	int lc = DemCot(a, m, n, 0);
	for (int j = 0; j < n; j++)
		if (DemCot(a, m, n, j) > lc)
			lc = DemCot(a, m, n, j);
	return lc;
}

void LietKe(int a[][100], int m, int n)
{
	cout << "Cac cot co nhieu chu so nhat la: ";
	for (int j = 0; j < n; j++)
		if (DemCot(a, m, n, j) == DemLonNhat(a, m, n))
			cout << setw(10) << j;
}
