#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void SapCotTang(float[][100], int, int, int);

int main()
{
	float b[100][100];
	int k, l, c;
	Nhap(b, k, l);

	cout << "Ma tran ban dau: \n";
	Xuat(b, k, l);

	cout << "Nhap cot muon sap xep: ";
	cin >> c;

	cout << "Mang sau khi sap xep: \n";
	SapCotTang(b, k, l, c);
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
			a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
}


void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void SapCotTang(float a[][100], int m, int n, int c)
{
	for (int i = 0; i <= m - 2; i++)
		for (int j = i + 1; j <= m - 1; j++)
			if (a[i][c] > a[j][c])
				HoanVi(a[i][c], a[j][c]);
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
