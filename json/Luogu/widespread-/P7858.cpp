#include<bits/stdc++.h>
using namespace std;
int x[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
string a[1010];
string b;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    cin >> b;
    for(int i = 1; i <= n; i++){
        if(a[i].length() == b.length()){
            bool flag = true;
            for(int j = 0; j < a[i].length(); j++){
                if(x[a[i][j] - 97] != b[j]-48)
                    flag = false;
            }
            if(flag) ans++;
        }
    }
    cout << ans;
    return 0;
}