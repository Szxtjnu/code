#include<bits/stdc++.h>
using namespace std;
int A, c[10];
int v[10] = {0,1,5,10,50,100,500};
int main(){
    int ans = 0;
    for(int i =1; i <= 6; i++){
        cin >> c[i];
    }
    cin >> A;
    int i = 6;
    while(A > 0){       
        int t = min(A / v[i], c[i]);
        A -= t * v[i];
        i--;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}