#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void SapDongTang(float[][100], int, int, int);

int main()
{
    float b[100][100];
    int k, l, d;
    Nhap(b, k, l);

    cout << "Ma tran ban dau: \n";
    Xuat(b, k, l);
    cout << "Nhap dong: ";
    cin >> d;

    SapDongTang(b, k, l, d);
    cout << "Sau khi sap xep: " << endl;
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

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void SapDongTang(float a[][100], int m, int n, int dd)
{
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[dd][i] > a[dd][j])
                HoanVi(a[dd][i], a[dd][j]);
}