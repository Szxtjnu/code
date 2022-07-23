#include<bits/stdc++.h>
using namespace std;
int n, s;//苹果数n，力气s
int a, b;//椅子高度a，手伸直最大长度b
int x[5005], y[5005];//苹果高度，需要的力气
pair<int, int> itv[5005];
int main(){
    cin >> n >> s;
    cin >> a >> b;
    int high = a + b;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&x[i],&y[i]);
        itv[i].first = y[i];
        itv[i].second = x[i];
    }
    sort(itv+1, itv+1+n);
    for(int i = 1; i <= n; i++){
        if(s >= itv[i].first){
            if(high >= itv[i].second){
                s -= itv[i].first;
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}