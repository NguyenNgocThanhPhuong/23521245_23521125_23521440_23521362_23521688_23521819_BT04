#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktDang5m(int);
void LietKe(int[][100], int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	int cc;
	cout << "Nhap cot can kiem tra: ";
	cin >> cc;

	LietKe(b, k, l, cc);
	cout << "\n\n\nKet thuc.";
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

bool ktDang5m(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 5)
		if (t % 5 != 0)
			flag = false;
	return flag;
}

void LietKe(int a[][100], int m, int n, int c)
{
	cout << "\nCac gia tri co dang 5^m tren cot " << c << ": ";
	for (int i = 0; i < m; i++)
		if (ktDang5m(a[i][c]) == true)
			cout << setw(10) << a[i][c];
}