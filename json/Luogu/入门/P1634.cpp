#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b;
    long long ans = 1;
    cin >> a >> b;
    for(long long i = 1; i <= b; i++){
        ans += ans * a;
    }
    cout << ans;
    return 0;
}