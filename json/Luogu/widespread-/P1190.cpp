#include<bits/stdc++.h>
using namespace std;
int m, n;//m个水龙头， n个同学
int w[10005];//节水量

int main(){
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",&w[i]);
    }
    int t = m + 1;
    while (t <= n + m)
    {
        for(int i = 1; i <= m; i++){
            w[i]--;
            if(w[i] == 0){
                w[i] = w[t];
                t++;
            }
        }
        ans ++;
    }
    cout << ans;
    return 0;
}