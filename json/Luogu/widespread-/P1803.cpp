#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int a[MAXN], b[MAXN];
pair<int, int> itv[MAXN];
int main(){
    int n;
    int ans = 0, t = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
        itv[i].first = b[i];
        itv[i].second = a[i];
    }
    sort(itv, itv+n);
    for(int i = 0; i < n; i++){
        if(t <= itv[i].second){
            ans++;
            t = itv[i].first;
        }
    }
    cout << ans;
    return 0;
}