#include<bits/stdc++.h>
using namespace std;
int m; // max weight
int n; // variety
int c[1005]; // value
int w[1005]; // weight
int dp[20000];
int main(){
    cin >> m >> n;
    for(int i =  1; i <= n; i++){
        scanf("%d%d",&c[i], &w[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j >= w[i]){
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }
    }
    cout << dp[m];
    return 0;
}