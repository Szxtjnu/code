#include<bits/stdc++.h>
using namespace std;
int d[10000005],a[10000000];
int N, M;
int main(){
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        scanf("%d",&d[i]);
    }
    for(int i = 1; i <= N; i++){
        scanf("%d",&a[i]);
    }
    sort(d+1, d+1+M);
    sort(a+1, a+1+N);
    int total = 0;
    int k = 1;
    for(int i = 1; i <= N; i ++){
        if(d[k] == 0) k++;      //注意0的问题，需要特殊标记
        if(d[k] < a[i] && d[k] != 0){
            a[i] = 0;
            k++;
        }
    }
    if(k <= M){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= N; i++){
        total += a[i];
        // cout << a[i] << endl;
    }
    cout << total << endl;
    return 0; 
}
