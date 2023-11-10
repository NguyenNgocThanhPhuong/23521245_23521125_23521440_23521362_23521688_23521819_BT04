#include<iostream>
#include<iomanip>

using namespace std;

void Nhap(double[][100], int&, int&);
void Xuat(double[][100], int, int);

int main()
{
	double b[100][100];
	int m, n;
	cout << "Ma tran: \n";
	Nhap(b, m, n);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, m, n);

	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(double a[][100], int& m, int& n)
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

void Xuat(double a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}