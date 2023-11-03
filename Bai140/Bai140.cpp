#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void SapZicZac(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	SapZicZac(b, k, l);

	cout << "Ma tran moi:\n";
	Xuat(b, k, l);
	cout << "\n\n\nKetthuc!";
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

void SapZicZac(float a[][100], int m, int n)
{
	float b[200];
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			b[k++] = a[i][j];
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
			if (b[i] > b[j])
				swap(b[i], b[j]);
	k = 0;
	for (int i = 0; i < m; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < n; j++)
				a[i][j] = b[k++];
		else
			for (int j = n - 1; j >= 0; j--)
				a[i][j] = b[k++];
	}

}
