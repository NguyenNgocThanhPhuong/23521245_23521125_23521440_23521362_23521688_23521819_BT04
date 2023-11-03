#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	LietKe(b, k, l);
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

void LietKe(int a[][100], int m, int n)
{
	cout << "\nCac gia tri nam tren bien: ";
	for (int j = 0; j <= n - 2; j++)
		cout << setw(10) << a[0][j];
	for (int i = 0; i <= m - 2; i++)
		cout << setw(10) << a[i][n - 1];
	for (int j = n - 1; j >= 1; j--)
		cout << setw(10) << a[m - 1][j];
	for (int i = m - 1; i >= 1; i--)
		cout << setw(10) << a[i][0];
}