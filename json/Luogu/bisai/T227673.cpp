#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int n;
        cin >> n;
        int idx = 0;
        for(int j = 1; j <= n; j++){
            int temp;
            cin >> temp;
            if(temp != 0){
                idx++;
            }
        }
        if(idx%2 == 0){cout << "NO" << endl;}
        else cout << "YES" << endl;
    }
    return 0;
}