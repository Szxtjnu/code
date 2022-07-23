#include<iostream>
#include<cmath>
const int MAXN = 1025;
int a[MAXN][MAXN];
using namespace std;
int main()
{
    int m, half = 1;
    cin >> m;
    int n = pow(2,m);
    int k = 1;
    a[0][0] = 1;
    while (k <= m)
    {
        for (int i = 0; i < half; ++i){
            for (int j = 0; j < half; ++j){
                a[i][j + half] = a[i][j] + half;
            }
        }
        for (int i = 0; i < half; ++i)
            for (int j = 0; j < half; ++j)
            {
                a[i + half][j] = a[i][j + half];
                a[i + half][j + half] = a[i][j];
            }
        half *= 2;
        ++k;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", a[i][j]);
        }
        cout << '\n';
        }
        return 0;
}