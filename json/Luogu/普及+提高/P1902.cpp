#include<bits/stdc++.h>
using namespace std;
#define N 1005
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int p[N][N], n, m, ans = 0x3f3f3f3f;
int f[N][N];
bool v[N][N];

struct node {
    int x, y, maxdamage;
};

node s[N*N];
int top;

void dfs(){
    while(top){
        int x = s[top].x, y = s[top].y, maxdamage = s[top].maxdamage;
        top--; v[x][y] = false;
        if(maxdamage >= ans) continue;
        if(x == n){
            ans = maxdamage;
            continue;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(v[nx][ny]) continue;
            int nextdamage = max(maxdamage, p[nx][ny]);
            if(f[nx][ny] <= nextdamage) continue;
            v[nx][ny] = true;
            f[nx][ny] = nextdamage;
            s[++top] = (node){nx, ny, nextdamage};
        }
    }
}
int main(){
    memset(f, 0x3f, sizeof(f));
    cin >> n >> m;
    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i = 1; i <= m; i++){
        v[2][i] = true;
        s[++top] = (node) {2, i, p[2][i]};
        dfs();
    }
    cout << ans << endl;
    return 0;
}