#include<bits/stdc++.h>
using namespace std;
int n; //the number of coin
bool a[105]; // the status of every coin
int main(){
    cin >> n;
    int t = 1;
    cout << n << endl;
    for(int i = 1; i <= n; i++){
        for(int i = 1; i <=n; i++){
            a[i] = !a[i];
        }
        a[t] = !a[t];
        t++;
        for(int i = 1; i <= n ;i++){
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}