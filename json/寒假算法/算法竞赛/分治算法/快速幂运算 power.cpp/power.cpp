#include<iostream>
#include<cmath>
using namespace std;
// int pow(int a, int b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     else
//     {
//         int c = pow(a, b / 2);
//         if ((b % 2) == 0)
//         {
//             return c * c;
//         }
//         else
//             return c * c * a;
//     }
// }
// int main()
// {
//     int X, n;
//     cin >> X >> n;
//     cout << pow(X, n) << endl;
//     return 0;
// }

long long pow(long long x, long long n)
{
    long long result = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        while ((n & 1) == 0) //如果n是偶数
        {
            n >>= 1;
            x *= x;
        }
    }
    result = x;
    while (n != 0)
    {
        n >>= 1;
        x *= x;
        if ((n & 1) != 0)
        {
            result *= x;
        }
    }
    return result;
}
int main()
{
    long long x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}