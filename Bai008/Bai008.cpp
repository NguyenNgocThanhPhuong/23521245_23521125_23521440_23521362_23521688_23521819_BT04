#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&, string);
void Xuat(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	Nhap(b, k, l, "floatmatrandata06.inp");

	cout << "Ma tran nhap tu tap tin floatmatrandata06.inp:\n";
	Xuat(b, k, l);
	return 0;
}

void Nhap(float a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}