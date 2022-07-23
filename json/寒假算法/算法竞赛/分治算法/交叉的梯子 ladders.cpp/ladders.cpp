#include<cmath>
#include<iostream>
using namespace std;
double x, y, c;
bool check(double t)
{
    double a, b;
    a = sqrt(x * x - t * t);
    b = sqrt(y * y - t * t);
    if (a*c+b*c-a*b> 0)
        return true;
    else
        return false;
}
int main()
{  
    while(~scanf("%lf%lf%lf",&x,&y,&c))
    {
        double r, l, mid;
        l = 0;
        r = (x > y ? y : x);
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (check(mid))
                r = mid - 0.0001;
            else
                l = mid + 0.0001;
        }
        printf("%.3lf", r);
    }
    return 0;
}
