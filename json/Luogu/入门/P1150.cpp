#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int temp = 0;
    while(n > 0){
        ans += n;
        temp += n % k;
        n = n / k;
        if(temp >= k){
            ans ++;
            temp -= k;
        }
    }
    cout << ans;
    return 0;
}