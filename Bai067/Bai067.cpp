#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
int DemChinhPhuongBien(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "Ma tran ban dau:\n";
    Xuat(b, k, l);

    cout << "So luong so chinh phuong: " << setw(10) << DemChinhPhuongBien(b, k, l);
    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap so dong: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
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

bool ktChinhPhuong(int n)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
        if (i * i == n)
            flag = true;
    return flag;
}

int DemChinhPhuongBien(int a[][100], int m, int n)
{
    int dem = 0;
    for (int j = 0; j <= n - 1; j++)
        if (ktChinhPhuong(a[0][j]))
            dem++;
    for (int j = 0; j <= n - 1; j++)
        if (ktChinhPhuong(a[m - 1][j]))
            dem++;
    for (int i = 1; i <= n - 2; i++)
        if (ktChinhPhuong(a[i][0]))
            dem++;
    for (int i = 1; i <= n - 2; i++)
        if (ktChinhPhuong(a[i][n - 1]))
            dem++;
    return dem;
}
