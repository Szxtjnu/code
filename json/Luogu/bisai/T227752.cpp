#include<bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010];
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, k;
        cin >> n >> k;
        int l = 0;
        if(l == 0){
            cout << "Impossible" << endl;
            continue;
        }else if(l >= 5){
            cout << "5 or more" << endl;
            for(int k = 1; k <= 5; k++){
                cout << c[k] << endl;
                continue;
            }
        }else{
            for(int k = 1; k <= l; k++){
                cout << c[k] << endl;
                continue;
            }
        }
    }
    return 0;
}