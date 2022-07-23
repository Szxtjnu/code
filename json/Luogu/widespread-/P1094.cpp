#include<bits/stdc++.h>
using namespace std;
int w, n;//每组价格最大值，物品的总件数
int p[30005];
int main(){
    cin >> w >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&p[i]);
    }
    sort(p+1, p+1+n);
    int ans = 0;
    int k = 1;
    for(int i = n; i >= 1; i--){
        if(p[i] > w || p[i] + p[k] > w){
            ans++;
            p[i] = -1;
        }
        else{
            if(p[i]!=-1){
                ans++;
                p[i] = p[k] = -1;
                k++;
            }
        }
    }
    cout << ans;
    return 0;
}