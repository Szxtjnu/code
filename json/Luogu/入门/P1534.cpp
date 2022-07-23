#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a, b, temp = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        temp = temp + a + b - 8;
        ans += temp;
    }
    cout << ans;
    return 0;
}