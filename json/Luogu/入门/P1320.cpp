#include<bits/stdc++.h>
using namespace std;
int main(){
    char a,b = '0';
    int n, ans[40010], idx = 1;
    while(cin >> a){
        n ++;
        if(a == b){
            ans[idx] ++;
        }
        else{
            ans[++idx] ++;
            b = a;
        }
    }
    cout << sqrt(n);
    for(int i = 1; i <= idx; i++){
        cout << " " << ans[i];
    }
    return 0;
}