#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int ViTriLonNhat(int[], int);
int TimChuSo(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;
    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau:\n";
    Xuat(b, k, l);

    cout << "\nChu so xuat hien nhieu nhat la: " << TimChuSo(b, k, l) << endl;

    cout << "\n\n\nKet Thuc!!!";
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
            cout << fixed << setw(10) << a[i][j];
        cout << endl;
    }
}

int ViTriLonNhat(int a[], int n)
{
    int lc = 0;
    for (int i = 0; i <= n - 1; i++)
        if (a[i] > a[lc])
            lc = i;
    return lc;
}

int TimChuSo(int a[][100], int m, int n)
{
    int dem[10] = { 0,0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i <= m - 1; i++)
        for (int j = 0; j <= n - 1; j++)
        {
            if (a[i][j] == 0)
                dem[0]++;
            int t = abs(a[i][j]);
            while (t != 0)
            {
                int dv = t % 10;
                dem[dv]++;
                t = t / 10;
            }
        }
    return ViTriLonNhat(dem, 10);
}