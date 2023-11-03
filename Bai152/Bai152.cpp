#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TichDong(float[][100], int, int, int);
void ThemCot(float[][100], int, int&);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	ThemCot(b, k, l);
	cout << "Ma tran sau khi them cot: \n";
	Xuat(b, k, l);

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
			a[i][j] = rand() / (float)(RAND_MAX / 200) - 100;
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

float TichDong(float a[][100], int m, int n, int d)
{
	float s = 1;
	for (int j = 0; j < n; j++)
		s = s * a[d][j];
	return s;
}

void ThemCot(float a[][100], int m, int& n)
{
	for (int i = 0; i < m; i++)
		a[i][n] = TichDong(a, m, n, i);
	n++;
}