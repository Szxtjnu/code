#include<bits/stdc++.h>
using namespace std;
int main(){
    double n, temp = 2.0, d = 0.0;
    cin >> n;
    int ans = 0;
    while(d < n){
        d += temp;
        temp = temp * 0.98;
        ans++; 
    }
    cout << ans;
    return 0;
}