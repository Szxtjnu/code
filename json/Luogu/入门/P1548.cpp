#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ,m;
    int ans1 = 0, ans2 = 0;
    cin >> n >> m;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            for(int k = i + 1; k <= m; k++){
                for(int l = j + 1; l <= n; l++){
                    if(k - i == l - j) ans1++;
                    else ans2++;
                }
            }
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}