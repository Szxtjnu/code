#include<iostream>
#include<cstring>
#define MAXN 5001
using namespace std;

int main()
{
    char str1[100], str2[100];
    int a[MAXN] = {0}, b[MAXN] = {0}, c[MAXN] = {0}, lena, lenb, lenc;
    int k;
    cin >> str1 >> str2;
    lena = strlen(str1);
    lenb = strlen(str2);
    for (int i = 0; i < lena; ++i)
        a[lena - i - 1] = str1[i] - 48;
    for (int i = 0; i < lenb; ++i)
        b[lenb - i - 1] = str2[i] - 48;
    for (int i = 0; i < lena; ++i){
        int x = 0;
        for (int j = 0; j < lenb; ++j){
            c[i + j] += a[i] * b[j];
            c[i + j] += x;
            x = c[i + j] / 10;
            c[i + j] %= 10;
        }
        c[i + lenb] = x;
    }
    lenc = lena + lenb;
    while (c[lenc] == 0 && lenc > 0)
        lenc--;

    for (int i = lenc  ; i >= 0; --i)
        {
            cout << c[i];
        }
    return 0;
}