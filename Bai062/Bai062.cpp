#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktLe(int);
int DemToanLe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "\nNhap ma tran " << endl;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
	Xuat(b, k, l);

	int dd;
	cout << "\nNhap dong: ";
	cin >> dd;

	cout << "So luong chu so le: " << DemToanLe(b, k, l, dd);
	cout << "\n\n\nKet thuc";
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

bool ktLe(int t)
{
	bool flag = true;
	int x = t;
	while (x > 0)
	{
		int dv = x % 10;
		if (dv % 2 == 0)
			flag = false;
		x = x / 10;
	}
	return flag;
}

int DemToanLe(int a[][100], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (ktLe(a[d][j]) == 1)
			dem = dem + 1;
	return dem;
}