#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int ViTriDuongDau(int[], int);
int ViTriDuongNhoNhat(int[], int);
int TimChuSo(int[][100], int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    cout << "Chu so xuat hien it nhat: " << setw(10) << TimChuSo(b, k, l) << endl;
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

int ViTriDuongDau(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            return i;
    return -1;
}

int ViTriDuongNhoNhat(int a[], int n)
{
    int lc = ViTriDuongDau(a, n);
    if (lc == -1)
        return -1;
    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] < a[lc])
            lc = i;
    return lc;
}

int TimChuSo(int a[][100], int m, int n)
{
    int dem[] = { 0,0,0,0,0,0,0,0,0,0 };
    int t, dv;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                dem[0]++;
            t = abs(a[i][j]);
            while (t != 0)
            {
                dv = t % 10;
                dem[dv]++;
                t = t / 10;
            }
        }
    return ViTriDuongNhoNhat(dem, 10);
}
