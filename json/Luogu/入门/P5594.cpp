#include<iostream>
int a[1005][1005],count[1005][1005],total[1005];
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(!count[j][a[i][j]]){
                count[j][a[i][j]] = 1;
                total[a[i][j]]++;
            }
        }
    }
    for(int i = 1; i <=k; i++){
        cout << total[i] << " ";
    }
    return 0;
}