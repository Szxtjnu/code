#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN = 100010;
long long a[MAXN], b[MAXN];

int compare(const void *p, const void *q)
{
    return *(long long *)p - *(long long *)q;
}
long long cal(long long a[], long long m, long long b[], long long n, long long mid)
{
    long long i,j;
    long long cnt = 0;
    j = n - 1;
    for (i = 0; i < m ; ++i){
        while (j >= 0 && a[i] + b[j] > mid)
        {
            --j;
        }
        cnt += (j + 1);
    }
    return cnt;
}

long long findk(long long a[], long long m, long long b[], long long n, long long k)
{
    long long min = a[0] + b[0];
    long long max = a[m - 1] + b[n - 1];
    long long mid;

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (k <= cal(a, m, b, n, mid)){
            max = mid - 1;
        }
        else{
            min = mid + 1;
        }
    }
    return min;
}

int main(int argc, char const *argv[])
{
    long long m, n, k, i;
    while (scanf("%lld%lld%lld", &m, &n, &k) != EOF)
    {
        for (i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        printf("%lld\n", findk(a, m, b, n, k));
    }
    return 0;
}
