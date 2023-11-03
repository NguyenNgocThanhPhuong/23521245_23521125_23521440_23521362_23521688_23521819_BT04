#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int TichSoChan(int[][100], int, int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau: \n";
    Xuat(b, k, l);

    int d;
    cout << "\nNhap dong can kiem tra : ";
    cin >> d;

    if (TichSoChan(b, k, l, d) == 1)
        cout << "\Cot " << d << "\nKhong co so chan" << endl;
    else
        cout << "\nTich cac so chan cot " << d << " : " << TichSoChan(b, k, l, d);

    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
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

int TichSoChan(int a[][100], int m, int n, int k)
{
    int t = 1;
    for (int i = 0; i < m; i++)
        if (a[i][k] % 2 == 0)
            t = t * a[i][k];
    return t;
}