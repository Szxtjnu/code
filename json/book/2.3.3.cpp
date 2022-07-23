#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1005
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N];
int main(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&w[i], &v[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= W; j++){
            for(int k = 0; k * w[i] <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][W];
    return 0;
}