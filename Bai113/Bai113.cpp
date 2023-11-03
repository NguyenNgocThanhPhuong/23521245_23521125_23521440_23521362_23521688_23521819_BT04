#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDong(int[][100], int, int, int);
void LietKe(int[][100], int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
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

bool ktDong(int a[][100], int m, int n, int d)
{
	bool flag = true;
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] % 2 != 0)
			flag = false;
	}
	return flag;
}

void LietKe(int a[][100], int m, int n)
{
	int flag = 1;
	for (int i = 0; i < m; i++)
	{
		if (ktDong(a, m, n, i))
		{
			if (flag == 1)
			{
				cout << "Cac dong chua toan gia tri chan: ";
				flag = 0;
			}
			cout << setw(10) << i;
		}
	}
	if (flag == 1)
		cout << "Ma tran khong co dong chua toan gia tri chan";
}