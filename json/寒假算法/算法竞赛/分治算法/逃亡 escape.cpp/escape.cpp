#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    float s, v1, v2, t1, t2, t3, t4, c1, c2, c;
    cin >> s >> v1 >> v2;
    c1 = 0, c2 = s;
    do
    {
        c = (c1 + c2) / 2;
        t3 = c / v2;
        t1 = t3 + (s - c) / v1;
        t4 = (c - t3 * v1) / (v1 + v2);
        t2 = t3 + t4 + (s - (t3 + t4) * v1) / v2;
        if (t1 < t2){
            c2 = c;
        }
        else{
            c1 = c;
        }
    } while (fabs(t1-t2)>1e-4);
    printf("%4.2f", t1);
    return 0;
}
