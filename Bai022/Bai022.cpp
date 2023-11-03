#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktToanLe(int);
void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	LietKe(b, l, k);

	cout << "\n\n\nKet thuc!!!";
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

bool ktToanLe(int k)
{
	if (k == 0)
		return false;
	bool flag = true;
	for (int t = k = abs(k); t != 0; t = t / 10)
	{
		int dv = t % 10;
		if (dv % 2 == 0)
			flag = false;
	}
	return flag;
}

void LietKe(int a[][100], int m, int n)
{
	cout << "\nLiet ke cac so nguyen toan le tren bien: ";
	for (int j = 0; j <= n - 2; j++)
		if (ktToanLe(a[0][j]))
			cout << fixed << setw(10) << a[0][j];
	for (int i = 0; i <= m - 1; i++)
		if (ktToanLe(a[i][n - 1]))
			cout << fixed << setw(10) << a[i][n - 1];
	for (int j = 0; j <= n - 2; j++)
		if (ktToanLe(a[m - 1][j]))
			cout << fixed << setw(10) << a[m - 1][j];
	for (int i = 1; i <= m - 2; i++)
		if (ktToanLe(a[i][0]))
			cout << fixed << setw(10) << a[i][0];
}