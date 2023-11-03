#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void Nhap(int[][100], int&, int&, string);
void Xuat(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	Nhap(b, k, l, "intmatrandata01.inp");

	cout << "Ma tran nhap tu tap tin intmatrandata01.inp:\n";
	Xuat(b, k, l);
	return 0;
}

void Nhap(int a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}