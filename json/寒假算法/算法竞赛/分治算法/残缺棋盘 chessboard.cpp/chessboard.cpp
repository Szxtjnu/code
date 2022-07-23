#include<iostream>
#include<cstdio>
using namespace std;
int k = 1, c[1024][1024];

void lt(int x1, int y1, int x2, int y2)
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 4;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 4;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 4;
}

void lb(int x1, int y1, int x2, int y2)
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 2;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 2;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 2;
}

void rt(int x1,int y1,int x2,int y2)
{
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 3;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 3;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 3;
}

void rb(int x1,int y1,int x2,int y2)
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 1;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 1;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 1;
}

void cover(int x1, int y1, int x2, int y2)
{
    int i, j, p =1, q =1;
    if (x2 - x1 == 1)
    {
        for (i = x1; i <= x2; ++i)
            for (j = y1; j <= y2; ++j){
                if (c[i][j] != 0){
                    p = i;
                    q = j;
                }
            }
        if (p == x1 &&q == y1)
            lt(x1, y1, x2, y2);
        if (p == x1 && q == y2)
            lb(x1, y1,x2, y2);
        if (p == x2 && q == y1)
            rt(x1, y1,x2, y2);
        if (p == x2 && q == y2)
            rb(x1, y1,x2, y2);
    }
    else
    {
        for (i = x1; i <= x2; ++i)
            for (j = y1; j <= y2; ++j){
                if (c[i][j] != 0){
                    p = i;
                    q = j;
                }
            }
        if (p <= (x1 + (x2 - x1) / 2))
            {if (q <= (y1 + (y2 - y1) / 2))
                lt(x1, y1, x2, y2);
            else
                lb(x1, y1, x2, y2);}
        if (p > (x1 + (x2 - x1) / 2))
            {if (q <= (y1 + (y2 - y1) / 2))
                rt(x1, y1, x2, y2);
            else
                rb(x1, y1, x2, y2);}
        cover(x1, y1, (x1 + (x2 - x1) / 2), (y1 + (y2 - y1)/2));
        cover((x1 + (x2 - x1) / 2 + 1), y1, x2, (y1 + (y2 - y1) / 2));
        cover(x1, (y1 + (y2 - y1) / 2 + 1), (x1 + (x2 - x1) / 2), y2);
        cover((x1 + (x2 - x1) / 2 + 1), (y1 + (y2 - y1) / 2 + 1), x2, y2);
    }
}

void out()
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << c[j][i] << ' ';
        }
        cout << endl;
    }   
}

int main()
{
    int n, x, y;
    cin >> n >> y >> x;
    for (int i = 1; i <= n; i++)
    {
        k = k * 2;
    }
    c[x][y] = 7;
    cover(1, 1, k, k);
    out();
    return 0;
}
