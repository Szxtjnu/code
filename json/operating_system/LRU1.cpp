#include<bits/stdc++.h>
using namespace std;
#define M 3
#define N 20
struct Page
{
    int num;
    int time;
};

Page b[M];
int c[M][N];
int que[100];
int K;

void Init(Page *b, int c[M][N]){
    for (int i = 0; i < N; i++)
    {
        b[i].num = -1;
        b[i].time = N - i + 1;
    }
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            c[i][j] = -1;
        }
    }
}

int GetMax(Page *b){
    int max = -1;
    int tag = 0;
    for(int i = 0; i < M; i++){
        if(b[i].time > max){
            max = b[i].time;
            tag = i;
        }
    }
    return tag;
}

int Equ(int fold, Page *b){
    for(int i = 0; i < M; i++){
        if(fold == b[i].num){
            return i;
        }
    }
    return -1;
}

void Lru(int fold, Page *b){
    int val = Equ(fold, b);
    if(val >= 0){
        b[val].time = 0;
        for(int i = 0; i < M; i++){
            if(i != val){
                b[i].time++;
            }
        }
    }else{
        que[++K] = fold;
        val = GetMax(b);
        b[val].num = fold;
        b[val].time = 0;
        for(int i = 0; i < M; i++){
            if(i != val){
                b[i].time++;
            }
        }
    }
}

int main(){
    K = -1;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    Init(b,c);
    for(int i = 0; i < N; i++){
        Lru(a[i],b);
        c[0][i] = a[i];
        for(int j = 0; j < M; j++){
            c[j][i] = b[j].num;
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(c[i][j] == -1) {
                cout << "\t";
            }else{
                cout << c[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "ȱҳΪ:" << K+1 << endl;
    cout << "ȱҳΪ:" << (float)(K+1)/N << endl;
    return 0;
}