#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void SapCotTang(float[][100], int, int);
void SapCotGiam(float[][100], int, int);
void SapXep(float[][100], int, int);
void HoanVi(float&, float&);

int main()
{
    float b[100][100];
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

void Nhap(float a[][100], int& m, int& n)
{
    cout << "\nNhap so dong : ";
    cin >> m;
    cout << "\nNhap so cot : ";
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -100 + rand() / ((float)RAND_MAX / 200);
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

void SapXep(float a[][100], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
            SapCotGiam(a, m, j);
        else
            SapCotTang(a, m, j);
    }
}

void HoanVi(float& a, float& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void SapCotGiam(float a[][100], int m, int n)
{
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (a[i][n] < a[j][n])
                HoanVi(a[i][n], a[j][n]);
}

void SapCotTang(float a[][100], int m, int n)
{
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (a[i][n] > a[j][n])
                HoanVi(a[i][n], a[j][n]);
}
