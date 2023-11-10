#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDoiXung(int);
int TongDong(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap dong d muon tinh: ";
	cin >> d;

	cout << "\nTong cac gia tri thoa dieu kien tren dong " << d << ": ";
	cout << setw(10) << TongDong(b, k, l, d);

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

bool ktDoiXung(int n)
{
	int t = n;
	int dn = 0;
	while (t != 0)
	{
		int dv = t % 10;
		dn = dn * 10 + dv;
		t = t / 10;
	}
	if (dn == n)
		return true;
	return false;
}

int TongDong(int a[][100], int m, int n, int d)
{
	if (d > m)
		return 0;
	int s = 0;
	for (int j = 0; j < n; j++)
		if (ktDoiXung(a[d][j]))
			s = s + a[d][j];
	return s;
}