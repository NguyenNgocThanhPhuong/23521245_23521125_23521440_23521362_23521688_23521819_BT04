#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

bool kt(float[][100], int, int);
float TongCucDai(float[][100], int, int);
bool ktCucDai(float[][100], int, int, int, int);

int main()
{
    float b[100][100];
    int k, l;
    cout << "Ma tran \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : \n";
    Xuat(b, k, l);

    if (kt(b, k, l))
        cout << "\nTong cac so cuc dai : " << TongCucDai(b, k, l);
    else
        cout << "\nMa tran khong co so cuc dai";

    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
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

bool kt(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktCucDai(a, m, n, i, j))
                return true;
    return false;
}

bool ktCucDai(float a[][100], int m, int n, int d, int c)
{
    bool flag = true;
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++)
            if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && !(di == 0 && dj == 0))
                if (a[d + di][c + dj] > a[d][c])
                    flag = false;
    return flag;
}

float TongCucDai(float a[][100], int m, int n)
{
    float s = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktCucDai(a, m,n,i,j))
                s = s + a[i][j];
    return s;
}