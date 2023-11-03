#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int DemPhanBiet(float[][100], int, int, float[]);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	float c[100];
	cout << "\nSo gia tri phan biet trong ma tran : " << DemPhanBiet(b, k, l, c);
	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "\nNhap so dong : ";
	cin >> m;
	cout << "\nNhap so cot : ";
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

int DemPhanBiet(float a[][100], int m, int n, float b[])
{
	int dem = 1;
	int h = 1;
	int flag = 1;
	b[0] = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			flag = 1;
			for (int k = 0; k < h; k++)
				if (a[i][j] == b[k])
					flag = 0;
			if (flag == 1)
			{
				b[h] = a[i][j];
				dem++;
				h++;
			}
		}
	return dem;
}
