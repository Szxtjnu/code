#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1050
int n, m;
char a[MAX_N], b[MAX_N];
int dp[MAX_N][MAX_N];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m+1; i++){
        scanf("%c",&b[i]);
    }
    for(int i = 1; i <= n+1; i++){
        scanf("%c",&a[i]);
    }
    for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= m; j++){
            if(a[i]!=b[j]){
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << "  ";
        }
        cout <<endl;
    }
    return 0;
}