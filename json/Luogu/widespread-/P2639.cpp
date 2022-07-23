#include<bits/stdc++.h>
using namespace std;
int v[505], w[505], n;
int dp[45005];
int main(){
    int limit;
    cin >> limit;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        v[i] = w[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = limit; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[limit];
    return 0;
}