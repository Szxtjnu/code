/*
#include<bits/stdc++.h>
using namespace std;
int a[100];
int n, r;
void dfs(int k){
    if(k > r){
        for(int i = 1; i <= r; i++){
            cout << setw(3) << a[i];
        }
        cout << endl;
        return ;
    }
    for(int i = a[k-1]+1; i <= n; i++){
        a[k] = i;
        dfs(k+1);
    }
}
int main(){
    cin >> n >> r;
    dfs(1);
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int a[1005], n, m, arr = 1;
int main(){
    cin >> n >> m;
    while (arr){
        //达到边界打印解
        if(arr >= m + 1){
            for(int i = 1; i <= m; i++){
                cout << setw(3) << a[i];
            }
            cout << endl;
            arr--;
            continue;
        }
        if(!a[arr]){
            a[arr] = a[arr-1] + 1;
            arr++;
            continue;
        }
        //判定当前位为a[arr]的情况下，向后推
        //(m-arr)位是否超出题目的最大数字限制
        if(a[arr]+m-arr < n){
            a[arr++] ++;
            continue;
        }
        a[arr--] = 0;
    }
    return 0;
}