#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

float TichCot(float[][100], int, int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau: \n";
    Xuat(b, k, l);

    int c;
    cout << "\nNhap dong muon kiem tra: ";
    cin >> c;

    if (TichCot(b, k, l, c) == 1)
        cout << "\nKhong ton tai cac so thuoc [-1,0]";
    else
        cout << "\nTich cac so thuoc [-1,0] tren cot " << c << " là: " << TichCot(b, k, l, c) << endl;

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
            a[i][j] = rand() / (float)(RAND_MAX / 200) - 100;
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

float TichCot(float a[][100], int m, int n, int c)
{
    float s = 1;
    for (int i = 0; i < m; i++)
        if (a[i][c] <= 0 and a[i][c] >= -1)
            s = s * a[i][c];
    return s;
}