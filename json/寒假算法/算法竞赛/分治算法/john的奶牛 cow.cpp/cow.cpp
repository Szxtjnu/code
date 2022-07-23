#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100005;
int n, c;
int a[MAXN];
bool check(int k) 
{
    int tmp = a[0], cownum = 1;
    for (int  i = 0; i < n; ++i)
    {
        if (a[i] - tmp >= k)
        {
            tmp = a[i];
            cownum++;
        }
    }
    if (cownum >= c)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long l = 0, r = 3e9;
    int mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if(check(mid))
            l = mid + 1;
        else
            r = mid ;
    }
    printf("%lld",l - 1);
    return 0;
}