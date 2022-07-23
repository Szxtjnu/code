#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int mid, l, r, M, L, N, ans;
bool judge(int x){
    int tot = 0;
    int i = 0;
    int idx = 0;
    while (i < N+1)
    {
        i++;
        if(a[i] - a[idx] < x) tot++;
        else idx = i;
    }
    if(tot > M) return false;
    else return true; 
}
int main(){
    cin >> L >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    a[N+1] = L;
    l = 1; r = L;
    while(l <= r){
        mid = (l + r) / 2;
        if(judge(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}