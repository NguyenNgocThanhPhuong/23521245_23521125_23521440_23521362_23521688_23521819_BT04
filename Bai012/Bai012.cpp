#include <iostream>
#include <iomanip>
#include<cstdlib>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktNguyenTo(int);
void LietKe(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "Ma tran ban dau: \n";
    Xuat(b, k, l);

    LietKe(b, k, l);

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

bool ktNguyenTo(int k)
{
    int dem = 0;
    for (int i = 1; i <= k; i++)
        if (k % i == 0)
            dem++;
    if (dem == 2)
        return true;
    return false;
}

void LietKe(int a[][100], int m, int n)
{
    cout << "\nCac so nguyen to: ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktNguyenTo(a[i][j]))
                cout << setw(10) << a[i][j];
}