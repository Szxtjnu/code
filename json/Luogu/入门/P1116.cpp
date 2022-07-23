#include<bits/stdc++.h>
using namespace std;
int N; //车厢总数
int a[1005];
int main(){
    cin >> N;
    int temp, ans = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(a[i] > a[j]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}