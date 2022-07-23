#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;
int main()
{
    char a1[MAXN], b1[MAXN];
    int a[MAXN], b[MAXN], c[MAXN], lena, lenb, lenc, i, j, x;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    cin >> a1 >> b1;
    lena = strlen(a1);
    lenb = strlen(b1);
    for (i = 0; i < lena; ++i)
        a[lena - i] = a1[i] - 48;
    for (i = 0; i < lenb; ++i)
        b[lenb - i] = b1[i] - 48;
    for (i = 1; i <= lena; ++i)
    {
        x = 0;
        for (j = 1; j <= lenb; j++){
            c[i + j - 1] = a[i] * b[j] + x + c[i + j - 1];
            x = c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
        c[i + lenb] = x;
    }
    lenc = lena + lenb;
    while (c[lenc] == 0 && lenc > 1)
        lenc--;
    for (i = lenc; i > 0; i--)
        cout << c[i];
    return 0;
}