#include<bits/stdc++.h>
using namespace std;
int n, m; //需要牛奶总量；提供牛奶农民个数
int a[5005], b[5005]; //a表示单价，b表示最多的牛奶量
pair<int, int> itv[5005];
int main(){
    int ans = 0;
    cin >> n >> m;
    for(int i = 1 ; i <= m; i++){
        scanf("%d%d",&a[i], &b[i]);
        itv[i].first = a[i];
        itv[i].second = b[i];
    }
    sort(itv+1, itv+1+m);
    int k = 1;
    while(n > 0){
        if(n >= itv[k].second){
            ans += itv[k].first * itv[k].second;
            n -= itv[k].second;
            k++;
        }else{
            ans += itv[k].first * n;
            n = 0;
        }
    }
    cout << ans;
    return 0;
}