#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a, b;
    cin >> n;
    int ans = 1, temp = 0;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(i > 1)
        {if(a - b == 1){
            ans++;
        }
        else{
            temp = max(ans, temp);
            ans = 1;
        }}
        b = a;
    }
    cout << max(temp, ans);
    return 0;
}