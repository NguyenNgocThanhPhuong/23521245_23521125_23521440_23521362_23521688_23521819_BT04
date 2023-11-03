#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void HoanViCot(float[][100], int, int, int, int);
void HoanVi(float&, float&);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    int c1;
    cout << "\nNhap cot 1: ";
    cin >> c1;

    int c2;
    cout << "\nNhap cot 2: ";
    cin >> c2;

    HoanViCot(b, k, l, c1, c2);
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

void HoanViCot(float a[][100], int m, int n, int c1, int c2)
{
    for (int i = 0; i < m; i++)
        HoanVi(a[i][c1], a[i][c2]);
}
