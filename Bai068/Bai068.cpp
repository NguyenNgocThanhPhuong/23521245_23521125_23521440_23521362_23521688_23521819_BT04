#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemChuSo(int);
int DemChuSo(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << "So luong chu so trong ma tran la: ";
	cout << DemChuSo(b, k, l);

	cout << "\n\n\nKet Thuc!!!";
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
int DemChuSo(int n)
{
	int dem = 0;
	while (n != 0)
	{
		dem++;
		n = n / 10;
	}
	return dem;
}

int DemChuSo(int a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			dem = dem + DemChuSo(a[i][j]);
	return dem;
}