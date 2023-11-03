#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void SapDongGiam(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l;
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap dong muon sap xep: ";
	cin >> d;

	SapDongGiam(b, k, l, d);
	cout << "\nDong sau khi sap xep: \n";
	Xuat(b, k, l);

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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (200.0)));
}

void Xuat(float a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void SapDongGiam(float a[][100], int m, int n, int d)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[d][i] < a[d][j])
				HoanVi(a[d][i], a[d][j]);
}
