#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void LietKe(int[][100], int, int);

int main()
{
	int k, l;
	int b[100][100];

	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	LietKe(b, k, l);

	cout << "\n\n\nKet Thuc!";
	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap vao so hang: ";
	cin >> m;
	cout << "Nhap vao so cot: ";
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
	cout << "\nCac gia tri le tren cac dong chi so chan: ";
	for (int i = 0; i < m; i += 2)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 != 0)
				cout << setw(10) << a[i][j];
}