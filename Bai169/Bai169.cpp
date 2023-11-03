#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktCon(float[][100], int, int, float[][100], int, int);

int main()
{
	float b[100][100];
	float c[100][100];
	int k, l, g, h;
	cout << "Ma tran a:\n";
	Nhap(b, k, l);
	Xuat(b, k, l);

	cout << "Ma tran b:\n";
	Nhap(c, g, h);
	Xuat(c, g, h);


	if (ktCon(b, k, l, c, g, h) == 1)
		cout << "\nMang b la con cua mang a";
	else
		cout << "\nMang b khong la con cua mang a";
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

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int ktCon(float a[][100], int m, int n, float b[][100], int k, int l)
{
	if (m > k || n > l)
		return 0;
	int flag = 0;
	for (int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - n; c++)
		{
			int co = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (a[i][j] != b[d + i][c + j])
						co = 0;
			if (co == 1)
				flag = 1;
		}
	return flag;
}