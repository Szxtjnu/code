#include<bits/stdc++.h>
using namespace std;
int H[100005];
int main(){
    int N;
    long S = 0, B;
    cin >> N >> B;
    for(int i = 0; i < N; i ++){
        scanf("%d",&H[i]);
    }
    sort(H, H + N);
    int i = N - 1;
    int temp = 0;
    while(i >= 0){
        temp ++;
        S += H[i];
        if(S >= B){
            cout << temp << endl;
            break;
        }
        i--;
    }
    return 0;
}