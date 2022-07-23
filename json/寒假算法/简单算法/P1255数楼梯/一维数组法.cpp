#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int Maxn = 5005;
int a[Maxn], b[Maxn], c[Maxn],len = 1;
int main()
{
    a[1] = 1;
    b[1] = 2;
    c[1] = 1;
    int n;
    cin >> n;
    if (n != 0){
        for (int i = 3; i <= n; ++i)
        {
            memset(c, 0, sizeof(c));
            for (int j = 1; j <= len; ++j)
            {
                c[j] += a[j] + b[j];
                c[j + 1] += c[j] / 10;
                c[j] %= 10;
            }
            if (c[len + 1] > 0)
                len++;
            for (int j = 1; j <= len; ++j)
            {
                a[j] = b[j];
            }
            for (int j = 1; j <= len; ++j)
            {
                b[j] = c[j];
            }
        }
    for (int i = len ; i >= 1; --i){
        cout << c[i];
    }
    }
    else
        cout << 0;

    return 0;
}