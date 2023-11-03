#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void XoaCot(float[][100], int, int&, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	int cc;
	cout << "Nhap cot can xoa: ";
	cin >> cc;

	XoaCot(b, k, l, cc);
	cout << "\nMa tran sau khi xoa cot " << cc << ": \n";
	Xuat(b, k, l);
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
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

void XoaCot(float a[][100], int m, int& n, int c)
{
	for (int i = 0; i < m; i++)
		for (int j = c; j <= n - 2; j++)
			a[i][j] = a[i][j + 1];
	n--;
}
