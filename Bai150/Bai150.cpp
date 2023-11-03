#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float NhoNhatDong(float[][100], int, int, int);
void ThemCot(float[][100], int, int&);


int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nMa tran sau khi xu ly:\n";
	ThemCot(b, k, l);
	Xuat(b, k, l);

	cout << "\n\n\nKetthuc!!!";
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

float NhoNhatDong(float a[][100], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
		if (a[d][j] < lc)
			lc = a[d][j];
	return lc;
}

void ThemCot(float a[][100], int m, int& n)
{
	for (int i = 0; i < m; i++)
		a[i][n] = NhoNhatDong(a, m, n, i);
	n++;
}