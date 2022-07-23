#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == a[i-1]){
            i--;
            n--;
        }
    }
    int ans = 0;
    for(int i = 2; i < n; i++){
        if(a[i-1] > a[i] && a[i+1] > a[i]){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}