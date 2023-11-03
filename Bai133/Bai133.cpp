#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void HoanVi(int&, int&);
void LeGiam(int[][100], int, int);
void ChanTang(int[][100], int, int);
void ChanTangLeGiam(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    ChanTangLeGiam(b, k, l);
    cout << "Sau khi sap xep: " << endl;
    Xuat(b, k, l);
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

void HoanVi(int& a, int& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void ChanTang(int a[][100], int m, int n)
{
    int b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] % 2 == 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[j] < b[i])
                HoanVi(b[i], b[j]);
    k = 0;
    for (i = 0; i < m; i++)
        for (j = i; j < n; j++)
            if (a[i][j] % 2 == 0)
                a[i][j] = b[k++];
}

void LeGiam(int a[][100], int m, int n)
{
    int b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] % 2 != 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[j] > b[i])
                HoanVi(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = i; j < n; j++)
            if (a[i][j] % 2 != 0)
                a[i][j] = b[k++];
}

void ChanTangLeGiam(int a[][100], int m, int n)
{
    ChanTang(a, m, n);
    LeGiam(a, m, n);
}
