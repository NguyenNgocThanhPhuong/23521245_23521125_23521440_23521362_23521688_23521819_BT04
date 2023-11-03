#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float LonNhatCot(float[][100], int, int);
void ThemDong(float[][100], int&, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    cout << "\nMang sau khi them dong : \n" << endl;
    ThemDong(b, k, l);
    Xuat(b, k, l);

    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
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

float LonNhatCot(float a[][100], int m, int n)
{
    float lc = a[0][n];
    for (int i = 1; i < m; i++)
        if (a[i][n] > lc)
            lc = a[i][n];
    return lc;
}

void ThemDong(float a[][100], int& m, int n)
{
    for (int j = 0; j < n; j++)
        a[m][j] = LonNhatCot(a, m, j);
    m++;
}