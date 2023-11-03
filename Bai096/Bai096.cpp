#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhat(float[][100], int, int);
float NhoNhat(float[][100], int, int);
float LonNhi(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nGia tri lon thu nhi trong ma tran: " << LonNhi(b, k, l);
	cout << "\n\n\nKet Thuc!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

float LonNhat(float a[][100], int m, int n)
{
	float lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (lc < a[i][j])
				lc = a[i][j];
	return lc;
}

float NhoNhat(float a[][100], int m, int n)
{
	float lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (lc > a[i][j])
				lc = a[i][j];
	return lc;
}

float LonNhi(float a[][100], int m, int n)
{
	float ln = LonNhat(a, m, n);
	float lc = NhoNhat(a, m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (lc < a[i][j] && a[i][j] < ln)
				lc = a[i][j];
	return lc;
}