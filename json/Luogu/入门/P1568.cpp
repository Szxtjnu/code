#include<bits/stdc++.h>
using namespace std;
int a[1000000], b[1000000], c[1000000];
int main(){
    int n, m;
    int a1, b1;
    cin >> n >> m;
    int k = 1;
    long long temp1 = 0, temp2 = 0;
    int idx1 = 0,idx2 = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> a1 >> b1;
        idx1 += b1;
        while(b1){
            a[k++] = a1;
            b1--;
        }
    }
    k = 1;
    for(int i = 1; i <= m; i++){
        cin >> a1 >> b1;
        idx2 += b1;
        while(b1){
            b[k++] = a1;
            b1--;
        }
    }
    for(int i = 1; i <= min(idx1, idx2); i++){
        temp1 += a[i];
        temp2 += b[i];
        if(temp1 > temp2){
            c[i] = 1;
        }else if (temp1 <= temp2){
            c[i] = 0;
        }
    }
    for(int i = 2; i <= min(idx1, idx2); i++){
        if(c[i] == 0 && c[i-1] == 1)
            ans ++;
        if(c[i] == 1 && c[i-1] == 0)
            ans ++;
    }
    cout << ans;
    return 0;   
}