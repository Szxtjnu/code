#include<bits/stdc++.h>
using namespace std;
int n;
bool T[2000100];
double a[10005];
int t;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> t;
        int tmp[t + 600];
        int j;
        for(j = 1; j <= t; j++){
            tmp[j] = (int)(a[i] * (j * 1.0));
            if(T[tmp[j]] == true)
                T[tmp[j]] = false;
            else T[tmp[j]] = true;
        }
    }
    for(int i = 1; i <= 2000100; i++){
        if(T[i]){
            cout << i;
            break;
        }
    }
    return 0;
}