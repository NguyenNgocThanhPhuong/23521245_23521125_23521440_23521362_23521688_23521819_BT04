#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void NhapDong(int&, int&);
void HoanViDong(int[][100], int, int, int, int);

int main()
{
	int b[100][100];
	int k, l;

	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau : " << endl;
	Xuat(b, k, l);

	int l1, l2;
	NhapDong(l1, l2);

	HoanViDong(b, k, l, l1, l2);
	cout << "\nMa tran sau khi hoan vi dong " << l1 << " va " << l2 << " la:";
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

void NhapDong(int& d1, int& d2)
{
	cout << "\nNhap vao 2 dong can doi voi nhau:";
	cout << "\nDong dau tien, dong: ";
	cin >> d1;
	cout << "Dong thu 2, dong: ";
	cin >> d2;
}

void HoanViDong(int a[][100], int m, int n, int d1, int d2)
{
	for (int j = 0; j < n; j++)
		swap(a[d1][j], a[d2][j]);
}
