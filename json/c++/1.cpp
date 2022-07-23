#include<iostream>
using namespace std;
inline int max(int, int, int );
int main()
{
    int i, x, y, z;
    for (i = 0; i < 100000; ++i)
    {
        cin >> x >> y >> z;
        cout << max(x, y, z) << endl;
    }
    return 0;
}
inline int max(int a, int b, int c)	
{
    if(b > a) a = b;
    if(c > a) a = c;
    return a;
}