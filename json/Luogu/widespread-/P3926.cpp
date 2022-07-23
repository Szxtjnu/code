#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, c, p, q, r, x;
    cin >> a >> c >> p >> q >> r >> x;
    while(a < c){
        x -= p;
        if(x < 0){
            cout << a;
            return 0;
        }
        a++;
    }
    if(x < q){
        cout << a;
        return 0;
    }
    if(a == c){
        x -= q;
    }
    while(a >= c){
        x -= r;
        if(x < 0){
            cout << a;
            return 0;
        }
        a++;
    }
    return 0;
}