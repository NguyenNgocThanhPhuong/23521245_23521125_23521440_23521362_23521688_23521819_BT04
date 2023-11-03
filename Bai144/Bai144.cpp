#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int ktCot(float[][100], int, int, int);
void XoaCot(float[][100], int, int&, int);
void XoaCot(float[][100], int, int&);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    XoaCot(b, k, l);
    cout << "\nMa tran sau khi xoa: \n";
    Xuat(b, k, l);

    cout << "\n\n\nKet thuc!!!";
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

int ktCot(float a[][100], int m, int n, int c)
{
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i][c] > 0)
            flag1 = 1;
        if (a[i][c] < 0)
            flag2 = 1;
    }
    return flag1 * flag2;
}

void XoaCot(float a[][100], int m, int& n, int c)
{
    for (int i = 0; i < m; i++)
        for (int j = c; j <= n - 2; j++)
            a[i][j] = a[i][j + 1];
    n--;
}

void XoaCot(float a[][100], int m, int& n)
{
    for (int j = n - 1; j >= 0; j--)
        if (ktCot(a, m, n, j) == 1)
            XoaCot(a, m, n, j);
}
