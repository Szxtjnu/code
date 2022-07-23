#include<bits/stdc++.h>
using namespace std;
int M, N, ans;
int a[20000], b[20000];
bool cmp (int x, int y) {
    return x > y;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        scanf("%d",&a[i]);
    }
    ans = a[N] - a[1] + 1;
    for(int i = 1; i < N; i ++){
        b[i] = a[i+1] - a[i];
    }
    sort(b+1, b+N, cmp);
    for(int i = 1; i < M; i++){
        ans = ans - b[i] + 1;
    }
    cout << ans;
    return 0;
}