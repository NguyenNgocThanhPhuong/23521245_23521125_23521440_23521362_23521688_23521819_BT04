#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);

void LietKe(int[][100], int, int);
int ktDong(int[][100], int, int, int);

int main()
{
    int b[100][100];
    int k, l;

    cout << "Ma tran: \n";
    Nhap(b, k, l);

    cout << "\nMa tran ban dau : " << endl;
    Xuat(b, k, l);

    LietKe(b, k, l);

    cout << "\n\n\nKet thuc!!!";
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap m : ";
    cin >> m;
    cout << "Nhap n : ";
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

int ktDong(int a[][100], int m, int n, int d)
{
    for (int j = 0; j <= n - 1; j++)
        if (ktNguyenTo(a[d][j]))
            return d;
    return -1;
}

void LietKe(int a[][100], int m, int n)
{
    int flag = 0;
    cout << "\nCac dong thoa dieu kien: ";
    for (int i = 0; i < m; i++)
        if (ktDong(a, m, n, i) != -1)
        {
            cout << setw(10) << ktDong(a, m, n, i);
            flag = 1;
        }
    if (flag == 0)
        cout << "khong ton tai.";

}
