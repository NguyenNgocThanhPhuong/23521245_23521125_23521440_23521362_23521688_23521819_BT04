#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int DemDuongBien(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << DemDuongBien(b, k, l) << endl;

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

int DemDuongBien(float a[][100], int m, int n)
{
	int dem = 0;
	cout << "So luong cac so thuc duong tren bien la: ";
	for (int j = 0; j <= n - 2; j++)
		if (a[0][j] > 0)
			dem++;
	for (int i = 0; i <= m - 1; i++)
		if (a[i][n - 1] > 0)
			dem++;
	for (int j = 0; j <= n - 2; j++)
		if (a[m - 1][j] > 0)
			dem++;
	for (int i = 1; i <= m - 2; i++)
		if (a[i][0] > 0)
			dem++;
	return dem;
}

