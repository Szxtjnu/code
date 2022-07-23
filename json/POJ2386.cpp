#include<bits/stdc++.h>
using namespace std;
int N, M;
#define MAX_N 10000
#define MAX_M 10000

char A[MAX_N][MAX_M];

void dfs(int x, int y){
    A[x][y] = '.';
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            int nx = x + dx;
            int ny = y + dy;
            if(0 <= nx && nx < N && 0 <= ny && 
            ny < M && A[nx][ny] == 'W')  dfs(nx, ny);
        }
    }
    return;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(A[i][j] == 'W'){
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}