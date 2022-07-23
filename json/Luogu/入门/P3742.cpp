#include<bits/stdc++.h>
using namespace std;
int main(){
    long t, n, i;
    char x[101], z[101];
    cin >> n;
    cin >> x; cin >> z;
    for(int i = 0; i < n; i++){
        if(z[i] > x[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << z << endl;
    return 0;
}