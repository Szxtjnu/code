#include<iostream>
#include<cstdio>
using namespace std;
// int main()
// {
//     int base, power, k;
//     int result = 1;
//     cin >> base >> power >> k;
//     for (int  i = 1; i <= power; ++i)
//     {
//         result = result * base;
//         result = result % k;
//     }
//     result = result % k;
//     cout << result << endl;
//     return 0;
// }

int main()
{
    long long base, power;
    int k;
    int result = 1;
    cin >> base >> power >> k;
    base = base % k;//如果base大于k的话,这样算一下可以减少后面的复杂度
    if (power == 0)
    {
        result = 1;
    }
    
    while (power>0)
    {
        if (power % 2 == 1)
        {
            result = (result * base) % k;
        }
        power /= 2;
        base = (base * base) % k;
    }
    cout << result << endl;
    return 0;
}
