#include<bits/stdc++.h>
using namespace std;
int ans = 5;
void move(int k){
    if(k == 4){
        return ;
    }
    else {
        // cout << k << "," << k+1 << "-->" << 2*k+1 << "," << 2*k+2 << endl;
        // cout << 2*k << "," << 2*k-1 << "-->" << k << "," << k+1 << endl;
        ans += 2;
        move(k-1);
    }
    return ;
}
int main(){
    int n;
    cin >> n;
    if(n > 4) move(n);
    cout << ans << endl;
    return 0;
}