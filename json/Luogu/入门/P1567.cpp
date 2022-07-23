#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a, b, ans = 0, temp = 0;
    for(int i = 1; i <= n; i++){
        cin >> a;
        // if(i > 1)
        // {
            if(b < a)
                ans++;
            else{
                temp = max(ans, temp);
                ans = 1;
            }
        //}
        b = a;
    }
    cout << max(ans, temp);
    return 0;
}