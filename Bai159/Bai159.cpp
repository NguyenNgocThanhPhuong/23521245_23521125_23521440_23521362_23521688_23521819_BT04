#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DichPhai(float[], int);
void DichPhaiBien(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	DichPhaiBien(b, k, l);
	cout << "\nMa tran sau khi dich phai cac gia tri o bien: \n";
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

void DichPhai(float a[], int n)
{
	float temp = a[n - 1];
	for (int i = n - 1; i > 0; i--)
		a[i] = a[i - 1];
	a[0] = temp;
}

void DichPhaiBien(float a[][100], int m, int n)
{
	float b[100];
	int k;
	int i, j;

	k = 0;
	for (j = 0; j < n - 1; j++)
		b[k++] = a[0][j];
	for (i = 0; i < m - 1; i++)
		b[k++] = a[i][n - 1];
	for (j = n - 1; j > 0; j--)
		b[k++] = a[m - 1][j];
	for (i = m - 1; i > 0; i--)
		b[k++] = a[i][0];

	DichPhai(b, k);

	k = 0;
	for (j = 0; j < n - 1; j++)
		a[0][j] = b[k++];
	for (i = 0; i < m - 1; i++)
		a[i][n - 1] = b[k++];
	for (j = n - 1; j > 0; j--)
		a[m - 1][j] = b[k++];
	for (i = m - 1; i > 0; i--)
		a[i][0] = b[k++];
}