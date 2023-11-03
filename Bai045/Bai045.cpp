#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongDuong(float[][100], int, int);
int DemDuong(float[][100], int, int);
float TbcDuong(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau: \n";
    Xuat(b, k, l);

    cout << "\nTrung binh cong cac so duong la: " << fixed << setw(10) << setprecision(3) << TbcDuong(b, k, l);
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

int DemDuong(float a[][100], int m, int n)
{
    int dem = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] > 0)
                dem++;
    return dem;
}

float TongDuong(float a[][100], int m, int n)
{
    int tong = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] > 0)
                tong += a[i][j];
    return tong;
}

float TbcDuong(float a[][100], int m, int n)
{
    if (TongDuong(a, m, n) == 0)
        return 0;
    return TongDuong(a, m, n) / DemDuong(a, m, n);
}