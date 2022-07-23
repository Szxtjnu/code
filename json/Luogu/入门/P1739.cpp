#include<bits/stdc++.h>
using namespace std;
string a;
char c[256];
int main(){
    int ans = 0;
    cin >> a;
    int idx = 0;
    int k = 1;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '(' || a[i] == ')'){
            c[k] = a[i];
            k++;
        }
    }
    if(c[1] == ')'){
        cout << "NO";
        return 0;
    } 
    for(int i = 1; i <= k; i++){
        if(c[i] == '('){
            ans++;
            idx++;
        }
        if(c[i] == ')'){
            ans --;
            idx--;
        }
        if(idx < 0){
            cout << "NO";
            return 0;
        }
    }
    if(ans == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}