#include <bits/stdc++.h>
using namespace std;
#define N 14
#define inf 0x3f3f3f3f
int main()
{
    int a[N][N] = {

        {0, 20, inf, inf, 54, inf, 55, inf, inf, inf, 26, inf, inf, inf},
        {20, 0, 56, inf, 18, inf, inf, inf, inf, inf, inf, inf, inf, inf},
        {inf, 56, 0, 15, 44, 18, inf, inf, inf, inf, inf, inf, inf, inf},
        {inf, inf, 15, 0, inf, 28, inf, inf, inf, 26, inf, inf, inf, inf},
        {54, 18, 44, inf, 0, 51, 34, 56, 48, inf, inf, inf, inf, inf},
        {inf, inf, inf, 28, 51, 0, inf, inf, 27, 42, inf, inf, inf, inf},
        {55, inf, inf, inf, 34, inf, 0, 36, inf, inf, 26, 38, inf, inf},
        {inf, inf, inf, inf, 56, inf, 36, 0, 29, inf, inf, 33, 25, inf},
        {inf, inf, inf, inf, 48, 27, inf, 29, 0, 61, inf, 29, 42, 36},
        {inf, inf, inf, 26, inf, 42, inf, inf, 61, 0, inf, inf, inf, 25},
        {26, inf, inf, inf, inf, inf, 26, inf, inf, inf, 0, 24, inf, inf},
        {inf, inf, inf, inf, inf, inf, 38, 33, 29, inf, 24, 0, 34, inf},
        {inf, inf, inf, inf, inf, inf, inf, 25, 42, inf, inf, 34, 0, 47},
        {inf, inf, inf, inf, inf, inf, inf, inf, 36, 25, inf, inf, 47, 0}};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (a[j][k] > a[j][i] + a[i][k])
                    a[j][k] = a[j][i] + a[i][k];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}