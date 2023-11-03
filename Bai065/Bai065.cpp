#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemGiaTri(int[][100], int, int, int);
bool ChanDauTien(int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	int cc;
	cout << "\nNhap cot: ";
	cin >> cc;

	cout << "\nSo luong so nguyen thoa man dieu kien tren cot " << cc << ": " << DemGiaTri(b, k, l, cc);
	cout << "\n\n\nKet Thuc!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
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

bool ChanDauTien(int n)
{
	bool flag = false;
	int t = abs(n);
	while (t >= 10)
		t = t / 10;
	if (t % 2 == 0)
		flag = true;
	return flag;
}

int DemGiaTri(int a[][100], int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ChanDauTien(a[i][c]))
			dem++;
	return dem;
}