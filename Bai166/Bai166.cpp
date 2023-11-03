#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int ktCon(float[][100], int, int, int, int);
void ConDau(float[][100], int, int, int&, int&);
void XuatCon(float[][100], int, int);

int main()
{
	float b[100][100];
	int k, l;
	cout << "Ma tran: \n";
	Nhap(b, k, l);

	cout << "\nMa tran ban dau:\n";
	Xuat(b, k, l);

	int vtd, vtc;
	ConDau(b, k, l, vtd, vtc);

	if (vtd == -1 && vtc == -1)
		cout << "\nKhong co ma tran thoa dieu kien.";
	else
	{
		cout << "\nMa tran sau khi xu ly:\n";
		XuatCon(b, vtd, vtc);
	}

	cout << "\n\n\nKet Thuc!!!";
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
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
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

int ktCon(float a[][100], int m, int n, int vtd, int vtc)
{
	int flag = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[vtd + i][vtc + j] <= 0)
				flag = 0;
	return flag;
}

void ConDau(float a[][100], int m, int n, int& vtd, int& vtc)
{
	for (vtd = 0; vtd <= m - 3; vtd++)
		for (vtc = 0; vtc <= n - 3; vtc++)
			if (ktCon(a, m, n, vtd, vtc) == 1)
				return;
	vtd = vtc = -1;
}

void XuatCon(float a[][100], int vtd, int vtc)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << fixed << setw(10) << setprecision(3) << a[vtd + i][vtc + j];
		cout << endl;
	}
}