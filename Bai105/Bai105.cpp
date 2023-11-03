#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktDongTang(float[][100], int, int, int);

int main()
{
    float b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    int dd;
    cout << "\nNhap dong can kiem tra : ";
    cin >> dd;

    if (ktDongTang(b, k, l, dd))
        cout << "\nDong " << dd << " tang dan" << endl;
    else
        cout << "\nDong " << dd << " khong tang dan" << endl;
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

bool ktDongTang(float a[][100], int m, int n, int d)
{
    for (int j = 0; j < n - 1; j++)
        for (int h = j + 1; h < n; h++)
            if (a[d][h] < a[d][j])
                return false;
    return true;
}