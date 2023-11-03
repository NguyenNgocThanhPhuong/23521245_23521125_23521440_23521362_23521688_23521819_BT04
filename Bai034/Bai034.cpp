#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktNguyenTo(int);
int TongDong(int[][100], int, int, int);

int main()
{
    int b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau: \n";
    Xuat(b, k, l);

    int dd;
    cout << "\nNhap vao dong muon tinh tong:  ";
    cin >> dd;

    cout << "\nTong cac so nguyen to tren dong " << dd << " la: " << setw(10) << TongDong(b, k, l, dd);

    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap so dong: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
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

bool ktNguyenTo(int n)
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            dem++;
    if (dem == 2)
        return true;
    return false;
}

int TongDong(int a[][100], int m, int n, int d)
{
    int s = 0;
    for (int j = 0; j < n; j++)
        if (ktNguyenTo(a[d][j]))
            s += a[d][j];
    return s;
}