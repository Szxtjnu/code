#include<bits/stdc++.h>
using namespace std;
int A[3010];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d",&A[i]);
    }
    int t = 0, min = 0x3f3f3f3f;
    for(int i = 1; i <= n - m + 1; i++){
        for(int j = 1; j <= m; j ++){
            t += A[i+j-1];
        }
        if(t < min) min = t;
        t = 0;
    }
    cout << min << endl;
    return 0;
}