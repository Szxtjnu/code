#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a1,b1,c1;
    long long a2,b2,c2;
    int n;
    char t1,t2;
    cin >> a1 >> t1 >> b1 >> t2 >> c1;
    cin >> a2 >> t1 >> b2 >> t2 >> c2;
    cin >> n;
    c1 = a1 * 3600 + b1 * 60 + c1;
    c2 = a2 * 3600 + b2 * 60 + c2;
    long long ans = 0;
    ans = (c2 - c1) * n;
    cout << ans;
    return 0;
}