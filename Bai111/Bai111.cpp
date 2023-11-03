#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int ktDong(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	cout << "Cac dong thoa dieu kien la: ";
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
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
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

int ktDong(float a[][100], int m, int n, int d)
{
	int flagDuong = 0;
	int	flagAm = 0;
	int	flag = 0;
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] > 0)
			flagDuong = 1;
		if (a[d][j] < 0)
			flagAm = 1;
		if (a[d][j] == 0)
			flag = 1;
	}
	return flag * flagDuong * flagAm;
}

void LietKe(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			cout << setw(10) << i;
}