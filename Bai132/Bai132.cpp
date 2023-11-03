#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DuongGiam(float[][100], int, int);
void AmTang(float[][100], int, int);
void SapXep(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);;

    SapXep(b, k, l);
    cout << "\nMa tran luc sau: " << endl;
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

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void DuongGiam(float a[][100], int m, int n)
{
    float b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] < b[j])
                swap(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                a[i][j] = b[k++];
}

void AmTang(float a[][100], int m, int n)
{
    float b[100];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j])
                swap(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                a[i][j] = b[k++];
}

void SapXep(float a[][100], int m, int n)
{
    AmTang(a, m, n);
    DuongGiam(a, m, n);
}
