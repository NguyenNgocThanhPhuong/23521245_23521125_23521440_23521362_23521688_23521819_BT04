#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float Tong(float[][100], int, int, float, float);

int main()
{
	int k, l;
	float b[100][100];
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: ";
	Xuat(b, k, l);

	float xx;
	cout << "\nNhap x: ";
	cin >> xx;

	float yy;
	cout << "Nhap y: ";
	cin >> yy;

	cout << "\nTong cac gia tri nam trong doan " << "[" << xx << ", " << yy << "]: " << Tong(b, k, l, xx, yy);

	cout << "\n\n\nKet Thuc!";
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
			a[i][j] = rand() / (float)(RAND_MAX / 200) - 100;
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

float Tong(float a[][100], int m, int n, float x, float y)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x <= a[i][j] && a[i][j] <= y)
				s += a[i][j];
	return s;
}