#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemDong(int[][100], int, int);
int DemLonNhat(int[][100], int, int);
void LietKe(int[][100], int, int);
bool ktHoanThien(int);
bool kt(int[][100], int m, int n);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	if (kt(b, k, l))
	{
		cout << "\nDong co nhieu so hoan thien nhat : ";
		LietKe(b, k, l);
	}
	else
		cout << "\nMa tran khong co so hoan thien ";
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

bool ktHoanThien(int x)
{
	int s = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0)
			s = s + i;
	if (s == x)
		return true;
	return false;
}

bool kt(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktHoanThien(a[i][j]))
				return true;
	return false;
}

int DemDong(int a[][100], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (ktHoanThien(a[d][j]))
			dem++;
	return dem;
}

int DemLonNhat(int a[][100], int m, int n)
{
	int lc = DemDong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (DemDong(a, m, n, i) > lc)
			lc = DemDong(a, m, n, i);
	return lc;
}

void LietKe(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (DemDong(a, m, n, i) == DemLonNhat(a, m, n))
			cout << setw(10) << i;
}
