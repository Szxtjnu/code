#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i, j, k, m, n, sumx = 0, sumy =0;
    scanf("%lld",&n);
    for(i = 1; i <= n; i++){
        scanf("%lld%lld",&k, &m);
        sumx += k;
        sumy += m;
    }
    for(i = 1; i <= n; i++){
        scanf("%lld%lld",&k, &m);
        sumx -= k;
        sumy -= m;
    }
    printf("%lld",abs(sumx)+abs(sumy));
    return 0;
}