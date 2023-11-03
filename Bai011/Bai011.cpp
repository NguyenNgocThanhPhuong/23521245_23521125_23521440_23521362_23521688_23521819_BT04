#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

bool ktChinhPhuong(int);
void LietKe(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau: \n";
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
            a[i][j] = rand() % 201 - 100;
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

bool ktChinhPhuong(int k)
{
    bool flag = false;
    for (int i = 0; i <= k; i++)
        if (i * i == k)
            flag = true;
    return flag;
}

void LietKe(int a[][100], int m, int n)
{
    cout << "Cac so chinh phuong la: ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktChinhPhuong(a[i][j]))
                cout << fixed << setw(10) << a[i][j];
}