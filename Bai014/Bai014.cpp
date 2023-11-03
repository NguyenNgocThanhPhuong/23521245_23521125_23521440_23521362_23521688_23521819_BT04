#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDang2m(int);
void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau: \n";
	Xuat(b, k, l);

	LietKe(b, k, l);
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

bool ktDang2m(int n)
{
	if (n < 0)
		return false;
	bool flag = true;
	while (n > 1)
	{
		int du = n % 2;
		if (du != 0)
			flag = false;
		n = n / 2;
	}
	return flag;
}

void LietKe(int a[][100], int m, int n)
{
	cout << "Cac so nguyen co dang 2^m: ";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktDang2m(a[i][j]))
				cout << setw(10) << a[i][j];
}