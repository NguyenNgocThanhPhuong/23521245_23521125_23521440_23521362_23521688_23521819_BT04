#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int DemHoanThien(int[][100], int, int, int);
bool ktHoanThien(int);

int main()
{
    int b[100][100];
    int k, l;
    cout << "\nNhap ma tran " << endl;
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    int dd;
    cout << "\nNhap dong can kiem tra : ";
    cin >> dd;

    int kq = DemHoanThien(b, k, l, dd);
    if (kq == 0)
        cout << "\nDong " << dd << " khong co so hoan thien" << endl;
    else
        cout << "\nSo luong so hoan thien tren dong " << dd << " : " << kq;
    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "\nNhap so dong : ";
    cin >> m;
    cout << "\nNhap so cot : ";
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

bool ktHoanThien(int k)
{
    int s = 0;
    for (int i = 1; i < k; i++)
        if (k % i == 0)
            s = s + i;
    if (s == k)
        return true;
    return false;
}

int DemHoanThien(int a[][100], int m, int n, int d)
{
    int dem = 0;
    for (int j = 0; j < n; j++)
        if (ktHoanThien(a[d][j]))
            dem++;
    return dem;
}
