#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(long long[][100], int&, int&);
void Xuat(long long[][100], int, int);

int main()
{
	long long b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(long long a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}

void Xuat(long long a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << a[i][j];
		cout << endl;
	}
}