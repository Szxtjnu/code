/*简单高精度减法简版.cpp*/
#include<iostream>
#include<cstring>
using namespace std;

int a[100], b[100], c[100];
int lena, lenb, lenc;
int main()
{
    char x[100], y[100];
    cin >> x >> y;
    lena = strlen(x);
    lenb = strlen(y);
    for (int i = 0; i < lena; ++i)
    {
        a[lena - i] = x[i] - '0';
    }
    for (int i = 0; i < lenb; ++i)
    {
        b[lenb - i] = y[i] - '0';
    }
    for (int i = 1; i <= lena; ++i)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
    }
    while (c[lena] == 0 && lena > 1)
        lena--;

    for (int i = lena; i >= 1; i--)
    {
        cout << c[i];
        }
        return 0;
}