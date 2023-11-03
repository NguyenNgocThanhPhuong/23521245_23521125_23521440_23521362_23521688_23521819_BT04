#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhat(float[][100], int, int);
float LonNhatDong(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nDong chua gia tri lon nhat la: ";
	LietKe(b, k, l);
	cout << "\n\n\nKet thuc!!!";
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
			if (a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

float LonNhatDong(float a[][100], int m, int n, int dd)
{
	float lc = a[dd][0];
	for (int j = 0; j < n; j++)
		if (lc < a[dd][j])
			lc = a[dd][j];
	return lc;
}

void LietKe(float a[][100], int m, int n)
{
	float x = LonNhat(a, m, n);
	for (int i = 0; i < m; i++)
		if (LonNhatDong(a, m, n, i) == x)
			cout << setw(10) << i;
}