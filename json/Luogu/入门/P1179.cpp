#include<bits/stdc++.h>
using namespace std;
int main(){
    int l, r;
    int ans = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++){
        int temp = i;
        while(temp > 0){
            if(temp % 10 == 2) ans++;
            temp /= 10;
        }        
    }
    cout << ans;
    return 0;
}