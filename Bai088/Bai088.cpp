#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TongDong(float[][100], int, int, int);
float TongLonNhat(float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    cout << "\nTong dong lon nhat la: " << TongLonNhat(b, k, l) << endl;
    cout << "\n\n\nKet Thuc!!!";
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

float TongDong(float a[][100], int m, int n, int d)
{
    float s = 0;
    for (int j = 0; j < n; j++)
        s = s + a[d][j];
    return s;
}

float TongLonNhat(float a[][100], int m, int n)
{
    float lc = TongDong(a, m, n, 0);
    for (int i = 0; i < m; i++)
        if (lc < TongDong(a, m, n, i))
            lc = TongDong(a, m, n, i);
    return lc;
}