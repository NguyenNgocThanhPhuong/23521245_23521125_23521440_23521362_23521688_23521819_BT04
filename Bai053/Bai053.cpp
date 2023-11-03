#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int DemChinhPhuong(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\nSo luong so chinh phuong la: " << DemChinhPhuong(b, k, l);

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
			a[i][j] = rand() / (RAND_MAX / 200) - 100;
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

bool ktChinhPhuong(int x)
{
	bool flag = false;
	for (int i = 1; i <= x; i++)
		if (i * i == x)
			flag = true;
	return flag;
}

int DemChinhPhuong(int a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]))
				dem = dem + 1;
	return dem;
}