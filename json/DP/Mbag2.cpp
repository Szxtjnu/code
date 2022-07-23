//多重背包优化
#include<bits/stdc++.h>
using namespace std;
int maxV[201];
int weight[50]; // 拆分之后的物品重量
int value[50]; //拆分之后物品价值
int V; // 背包总容量
int N; // N种物品
int main(){
    cin >> V >> N;
    int wei, val, num;
    int count = 0;
    for(int i = 1; i <= N; i++){
        cin >> wei >> val >> num;
        for(int j = 1; j <= num; j <<= 1){
            weight[count] =  j * wei;   //the array_index of weight and value start from 0
            value[count++] = j * val;
            num -= j;
        }
        if(num > 0){
            weight[count] = num * wei;
            value[count++] = num * val;
        }
    }
    for(int i = 0; i < count; i++){
        for(int j = V; j >= weight[i]; j--){
            maxV[j] = max(maxV[j], maxV[j - weight[i]] + value[i]);
        }
    }
    cout << maxV[V];
    return 0;
}