#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemDong(int[][100], int, int);
int DemLonNhat(int[][100], int, int);
void LietKe(int[][100], int, int);
bool ktNguyenTo(int);
bool kt(int[][100], int m, int n);

int main()
{
	int b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "Ma tran ban dau:\n";
	Xuat(b, k, l);

	LietKe(b, k, l);
	cout << "\n\n\nKet Thuc!!!";
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

bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;
}

bool ktNguyenToDau(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]))
				return true;
	return false;
}

int DemDong(int a[][100], int m, int n)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (ktNguyenTo(a[m][j]))
			dem++;
	return dem;
}

int DemLonNhat(int a[][100], int m, int n)
{
	int lc = 0;
	for (int i = 0; i < m; i++)
		if (DemDong(a, i, n) > lc)
			lc = DemDong(a, i, n);
	return lc;
}

void LietKe(int a[][100], int m, int n)
{
	if (ktNguyenToDau(a, m, n))
	{
		cout << "Cac dong co nhieu so nguyen to nhat: ";
		for (int i = 0; i < m; i++)
			if (DemDong(a, i, n) == DemLonNhat(a, m, n))
				cout << setw(10) << i;
	}
	else
		cout << "Khong co nguyen to trong ma tran.";
}
