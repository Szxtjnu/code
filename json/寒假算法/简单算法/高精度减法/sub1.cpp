/*简单高精度减法.cpp*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 100000
using namespace std;

void sub(int x[], int y[], int len, int on)
{
    for (int i = 0; i < len; i++)
    {
        x[i] -= y[i];
        if (x[i] < 0)
        {
            --x[i + 1];
            x[i] += 10;
        }
        if (x[len - 1] == 0)
        {
            --len;
        }
    }
    for (int i = len-1; i >= 0; --i)
    {
        if (x[i] == 0)
        {
            len--;
        }
        if (x[i] != 0)
        {
            break;
        }
    }
    if (on == 1)
    {
        x[len - 1] = -x[len - 1];
    }
    for (int i = len - 1; i >= 0; --i)
    {
        cout << x[i];
    }
    cout << "\n";
}

void init(int x[], char temp[], int len)
{
    for (int  i = 0; i < len ; i++)
    {
        x[i] = temp[len - 1 - i] - '0';
    }
}

int main()
{
    char str1[MAXN], str2[MAXN];
    int lena, lenb, k, a[MAXN] = {0}, b[MAXN] = {0};
    cin >> str1 >> str2;
    lena = strlen(str1);
    lenb = strlen(str2);
    init(a, str1, lena);
    init(b, str2, lenb);
    if (lena > lenb)
    {
        sub(a, b, lena, 0);
    }
    else if (lena < lenb)
    {
        sub(b, a, lenb, 1);
    }
    else
    {
        k = strcmp(str1, str2);
        if (k > 0){
            sub(a, b, lena, 0);
        }
        else if (k == 0){
            cout << "0\n";
        }
        else{
            sub(b, a, lenb, 1);
        }
    }
    return 0;
}