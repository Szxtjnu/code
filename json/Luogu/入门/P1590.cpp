#include<bits/stdc++.h>
using namespace std;
long long k ,s = 1, sum = 0, ans = 0;
char a[1005];
int main(){
    int t;
    cin >> t;
    while(t--){
        ans = sum = 0;
        s = 1;
        cin >> a;
        k  = strlen(a);
        for(int i = 0; i < k; i++){
            if(a[i] == '7'){
                a[i] = '6';
                for(int j = i + 1; j < k; j++)
                    a[j] = '9';
                break;
            }
        }
        for(int i = k-1; i >= 0; i--){
            if(a[i] > '7') sum += s;
            s *= 9;
        }
        for(int i = 0; i < k; ++i){
            ans = ans * 9 + a[i] - '0';
        }
        cout << ans - sum << endl;
    }
    return 0;
}