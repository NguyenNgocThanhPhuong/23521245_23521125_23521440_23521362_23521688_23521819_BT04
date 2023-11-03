#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongDuong(float[][100], int, int, int);
float TongLonNhat(float[][100], int, int);
void LietKe(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	LietKe(b, k, l);

	cout << "\n\n\nKet Thuc!!!";
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

float TongDuong(float a[][100], int m, int n, int d)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s += a[d][j];
	return s;
}

float TongLonNhat(float a[][100], int m, int n)
{
	float lc = TongDuong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (TongDuong(a, m, n, i) > lc)
			lc = TongDuong(a, m, n, i);
	return lc;
}

void LietKe(float a[][100], int m, int n)
{
	cout << "Cac dong co tong lon nhat la: ";
	float lc = TongLonNhat(a, m, n);
	for (int i = 0; i < n; i++)
		if (TongDuong(a, m, n, i) == lc)
			cout << setw(10) << i;
}