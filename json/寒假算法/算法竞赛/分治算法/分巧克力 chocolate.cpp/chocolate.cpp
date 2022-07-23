#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAXN = 100010;
int hi[MAXN], wi[MAXN];
int main()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = 100000;
    for (int i = 0; i < n; ++i)
    {
        cin >> hi[i] >> wi[i];
    }
    while (l <= r)
    {   
        int tmp = 0;
        int mid = (l + r) / 2;
        for (int i = 0; i < MAXN; ++i)
        {
            int tmph = hi[i] / mid;
            int tmpw = wi[i] / mid;
            tmp += (tmph * tmpw);
        }
        if (tmp < k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << min(r, l) << endl;
    return 0;
}