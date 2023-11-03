#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int TanSuat(float[][100], int, int, float);
float TimGiaTri(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	cout << "\nGia tri xuat hien nhieu nhat trong mang: " << TimGiaTri(b, k, l);
	cout << "\n\n\nKet Thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][100], int m, int n)
{
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int TanSuat(float a[][100], int m, int n, float x)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x == a[i][j])
				dem++;
	return dem;
}

float TimGiaTri(float a[][100], int m, int n)
{
	float y = a[0][0];
	float lc = TanSuat(a, m, n, a[0][0]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (TanSuat(a, m, n, a[i][j]) > lc)
			{
				lc = TanSuat(a, m, n, a[i][j]);
				y = a[i][j];
			}
		}
	return y;
}
