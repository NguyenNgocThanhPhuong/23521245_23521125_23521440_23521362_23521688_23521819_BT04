#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool ktCotGiam(float[][100], int, int, int);

int main()
{
    float b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    int cc;
    cout << "\nNhap cot can kiem tra : ";
    cin >> cc;

    if (ktCotGiam(b, k, l, cc))
        cout << "\nCot " << cc << " giam dan" << endl;
    else
        cout << "\nCot " << cc << " khong giam dan" << endl;
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

bool ktCotGiam(float a[][100], int m, int n, int xx)
{
    for (int i = 0; i < m - 1; i++)
        for (int j = 1; j < m; j++)
            if (a[i][xx] < a[j][xx])
                return false;
    return true;
}
