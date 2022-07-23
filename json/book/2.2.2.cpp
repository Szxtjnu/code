#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }
    for(int i = 0; i < N; i++){
        itv[i].first = T[i];//存放结束时间
        itv[i].second = S[i];//存放开始时间
    }
    //排序过后是按照结束的时间升序排序，结束的越早的在前面
    sort(itv, itv + N);
    int ans = 0, t = 0;
    for(int i = 0; i < N; i++){
        //如果一个结束时间小于开始时间，那么这个开始时间便可以被选中
        //又因为开始时间的顺序是跟着结束时间走的，那么这个被选中的开始
        //时间一定是最合适的时间节点
        if(t < itv[i].second){ 
            ans ++ ;
            t = itv[i].first;//将结束时间赋值给t，进行下一步判断
        }
    }
    cout << ans << endl;
    return 0;
}