#include<bits/stdc++.h>
using namespace std;
int num[101], val[101], weig[101];
int dp[101];
int main(){
    int V, n;
    cin >> V >> n;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&weig[i], &val[i], &num[i]);
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < num[i]; j++){
            for(int k = V; k >= weig[i]; k--){
                dp[k] = max(dp[k], dp[k - weig[i]] + val[i]);
                if(dp[k] > ans)
                    ans = dp[k];
            }
        }
    }
    cout << ans;
    return 0;
}