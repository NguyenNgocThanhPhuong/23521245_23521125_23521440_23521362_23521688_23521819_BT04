#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void SapDongTang(float[][500], int, int, int);
void SapDongGiam(float[][500], int, int, int);
void SapXep(float[][500], int, int);
void HoanVi(float&, float&);

int main()
{
    float b[500][500];
    int k, l;

    cout << "\nNhap ma tran " << endl;
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    SapXep(b, k, l);
    cout << "\nMa tran sau sap xep : " << endl;
    Xuat(b, k, l);
    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
    cout << "\nNhap so dong : ";
    cin >> m;
    cout << "\nNhap so cot : ";
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -500 + rand() / ((float)RAND_MAX / 200);
}

void Xuat(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << fixed << setw(10) << setprecision(3) << a[i][j];
        cout << endl;
    }
}

void SapXep(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
            SapDongGiam(a, m, n, i);
        else
            SapDongTang(a, m, n, i);
    }
}

void HoanVi(float& a, float& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void SapDongGiam(float a[][500], int m, int n, int d)
{
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[d][i] < a[d][j])
                HoanVi(a[d][i], a[d][j]);
}

void SapDongTang(float a[][500], int m, int n, int d)
{
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[d][i] > a[d][j])
                HoanVi(a[d][i], a[d][j]);
}