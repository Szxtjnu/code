#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
int n, W;//n为物品数量，W为限制总价值
int w[MAX_N], v[MAX_N];
int dp[MAX_N];//i代表第几个物品，j代表背包容量
int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        scanf("%d%d",&w[i], &v[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = W; j >= 1; j--){
            if(j >= w[i]){
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[W];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < W; j++){
    //         if(j < v[i]){
    //             dp[i][j] = dp[i-1][j];
    //         }
    //         else{
    //             dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
    //         }
    //     }
    // }
    // cout << dp[n-1][w-1];
    return 0;
}