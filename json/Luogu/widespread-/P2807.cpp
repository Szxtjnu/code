#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
    for(int i = 1; i <= 505; i++){
        a[i] = a[i-1] + i;
    }
    int n;
    cin >> n;
    while(n-->0){
        int t, ans = 0;
        cin >> t;
        for(int i = 1; i <= t; i++){
            ans += a[t-i+1];   
        }
        for(int i = 1; i <= t/2; i++){
            ans += a[t-i*2+1];
        }
        cout << ans << endl;
    }
    return 0;
}