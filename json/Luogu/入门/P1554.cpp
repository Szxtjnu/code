#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    int m,n;
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        int idx = 0;
        int j = i;
        while(j)
        {
            idx = j % 10;
            j = j/10;
            a[idx]++;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}