#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float DuongDau(float[][100], int, int);
float DuongNhoNhat(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "Ma tran ban dau:\n";
    Xuat(b, k, l);

    float dd = DuongNhoNhat(b, k, l);
    if (dd == 0)
        cout << "\nMa tran khong co so duong";
    else
        cout << "\nSo duong nho nhat cua ma tran: " << dd;
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

float DuongDau(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] > 0)
                return a[i][j];
    return 0;
}

float DuongNhoNhat(float a[][100], int m, int n)
{
    float lc = DuongDau(a, m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((a[i][j] < lc) && (a[i][j] > 0))
                lc = a[i][j];
    return lc;
}
