#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TichCot(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: ";
	Xuat(b, k, l);

	int cc;
	cout << "\nNhap cot: ";
	cin >> cc;

	cout << "\nTich cac gia tri duong tren cot " << cc << ": " << TichCot(b, k, l, cc);
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
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

float TichCot(float a[][100], int m, int n, int c)
{
	if (c > n)
		return -1;
	float t = 1;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] > 0)
			t *= a[i][c];
	}
	return t;
}