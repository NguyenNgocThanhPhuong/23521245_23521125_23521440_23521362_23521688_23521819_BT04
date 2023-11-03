#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void ChanGiam1(int[][100], int, int);
void ChanGiam2(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
	Xuat(b, k, l);

	cout << "\Ma tran sau khi sap xep giam dan theo hang va cot: ";
	ChanGiam1(b, k, l);
	cout << "\n- Doi voi phuong phap su dung mang phu:";
	Xuat(b, k, l);

	ChanGiam2(b, k, l);
	cout << "\n- Doi voi phuong phap khong su dung mang phu:";
	Xuat(b, k, l);
	cout << "\n\n\nKet Thuc!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(10) << a[i][j];
		cout << endl;
	}
}

// s? d?ng mãng ph?
void ChanGiam1(int a[][100], int m, int n)
{
	int b[100];
	int k = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];

	for (int i = 0; i <= k - 2; i++)
		for (int j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				swap(b[i], b[j]);

	k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				a[i][j] = b[k++];
}

//không s? d?ng mãng ph?
void ChanGiam2(int a[][100], int m, int n)
{
	for (int k = 0; k <= m * n - 2; k++)
		for (int l = k + 1; l <= m * n - 1; l++)
			if (a[k / n][k % n] < a[l / n][l % n] && a[k / n][k % n] % 2 == 0 && a[l / n][l % n] % 2 == 0)
				swap(a[k / n][k % n], a[l / n][l % n]);
}
