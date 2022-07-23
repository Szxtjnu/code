#include<bits/stdc++.h>
using namespace std;
int A[10005][10005];
int n;
struct re{
    int x;
    int y;
};
int cal(re R){
    int num = 0;
    for(int i = 0; i < n; i++){
        if(A[R.x][i])
            num += A[R.x][i];
    }
    for(int i = 0; i < n; i++){
        if(A[i][R.y])
            num += A[i][R.y];
    }
    return num;
}
int main(){
    re M[10000];
    int ans[10000];
    int t = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&A[i][j]);
            if(!A[i][j]){
                M[t].x = i;
                M[t].y = j;
                t++;
            }
        }
    }
    if(!t){
        cout << "Bad Game!" << endl;
        return 0;
    }
    for(int i = 0; i < t; i ++){
        ans[i] = cal(M[i]);
    }
    sort(ans, ans+t, greater<int>());
    cout << ans[0] << endl;
    return 0;
}