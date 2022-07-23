#include<bits/stdc++.h>
using namespace std;
bool a[105][105];
// int mxy[105][105], kxy[105][105];
int main(){
    int n, m, k;
    int x, y;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        for(int j = x-2; j <= x+2; j++){
            if(j > 0){
                a[j][y] = true;
            }
        }
        for(int j = y-2; j <= y+2; j++){
            if(j > 0){
                a[x][j] = true;
            }
        }
        for(int j = x-1; j <= x+1; j++){
            for(int k = y-1; k <= y+1; k++){
                if(j>0 && k>0){
                    a[j][k] = true;
                }
            }
        }
    }
    for(int i = 1; i <= k; i++){
        cin >> x >> y;
        for(int j = x-2; j <= x+2; j++){
            for(int k = y-2; k <= y+2; k++){
                if(j>0 && k>0){
                    a[j][k] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!a[i][j]){
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}