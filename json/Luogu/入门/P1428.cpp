#include<bits/stdc++.h>
using namespace std;
int a[105], b[105];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = i; j >= 1; j--){
            if(a[i] > a[j])
                b[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
    return 0;
}