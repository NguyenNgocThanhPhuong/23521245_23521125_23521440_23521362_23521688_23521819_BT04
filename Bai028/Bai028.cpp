#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktToanChan(int);
int TongToanChan(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    cout << "\nTong cac so toan chan trong ma tran : " << TongToanChan(b, k, l);

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

bool ktToanChan(int n)
{
    bool flag = true;
    int t = n;
    while (t != 0)
    {
        int dv = t % 10;
        if (dv % 2 != 0)
            flag = false;
        t = t / 10;
    }
    return flag;
}

int TongToanChan(int a[][100], int m, int n)
{
    int s = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktToanChan(a[i][j]))
                s = s + a[i][j];
    return s;
}