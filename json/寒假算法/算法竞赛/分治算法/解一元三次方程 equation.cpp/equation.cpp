#include<iostream>
#include<cmath>
using namespace std;
float a, b, c, d;
int n = 0;
float ans[4];
float fun(double x)
{
    return (a * (x * x * x) + b * x * x + c * x + d);
}
void solve(float l, float r) 
{
    if ((fun(r) * fun(l) > 0) && ((r - l) < 1))
        return;
    float mid = (r + l) / 2;
    if (fabs(fun(mid))<1e-4)
    {
        ans[++n] = mid;
        return;
    }
    solve(l, mid);
    solve(mid, r);
}
int main()
{
    cin >> a >> b >> c >> d;
    solve(-100, 100);
    for (int i = 1; i <= n; ++i)
    {
        printf("%3.2f   ", ans[i]);
    }
    return 0;
}