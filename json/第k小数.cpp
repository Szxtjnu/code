#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 100000
typedef long long LL;

LL A[MAXN], B[MAXN];

int compare(const void * p, const void * q){
    return *(LL *)p - *(LL *)q;
}


LL cal(LL A[], LL m , LL B[], LL n, LL mid){
    LL i, j;
    LL cnt = 0;
    j = n-1;
    for(i=0; i<m; i++) {
        while(j>=0 && A[i]+B[j]>mid){
            --j;
        }
        cnt += (j+1);
    }
    return cnt;
}

LL findKth(LL A[], LL m, LL B[], LL n, LL k){
    LL min = A[0] + B[0];
    LL max = A[m-1] + B[n-1];
    LL mid;

    while(min <= max){
        mid = ((max-min) >> 1) + min;
        if(k <= cal(A,m,B,n,mid))
            max = mid - 1;
        else
            min = mid + 1;
    }

    return min;
}

int main(){
    LL m,n,k,i;
    cin >> m >> n >> k;
        for(i=0; i<m; ++i){
            cin >> A[i];
        }
        for(i=0; i<n; ++i ){
            cin >> B[i];
        }
        qsort(A,m,sizeof(LL),compare);
        qsort(B,n,sizeof(LL),compare);
        cout << findKth(A, m, B, n, k) << endl;
    
    return 0;
}