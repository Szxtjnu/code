#include<bits/stdc++.h>
using namespace std;
int a[1005], c[1005];
int n;
int main(){
    bool flag = true;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        c[i] = abs(a[i] - a[i+1]);
    }
    sort(c+1, c+n);
    for(int i = 1; i < n; i++){
        if(c[i] != i){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Jolly";
    }else{
        cout << "Not jolly";
    }
    return 0;
}