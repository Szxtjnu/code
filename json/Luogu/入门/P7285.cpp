// // 如果要使x-y最大，那么就要让x尽可能大，y尽可能小
// // T表示数据组数，2×T行每两行表示一组数据
// // 一组数据中第一行n表示数组长度，第二行n个数表示给定的数组
// // 输出2×T行，第一行输出一个整数表示x-y的最大值
// // 第二行输出修改后的数组
// #include<bits/stdc++.h>
// using namespace std;
// struct T{
//     int n;
//     bool N[100005];
// };
// T t[15];

// int main(){
//     int m;
//     cin >> m;
//     for(int i = 0; i < m; i++){
//         cin >> t[i].n;
//         for(int j = 0; j < t[i].n; j++){
//             cin >> t[i].N[j];
//         }
//     }
//     for(int i = 0; i < m; i++){
//         int idx = -1;
//         int count1 = 0, count2 = 0;
//         for(int j = 0; j < t[i].n; j++){
//             if(t[i].N[j]) {
//                 idx = j;
//                 break;
//             }
//         }
//         if(idx != -1) {
//         for(int j = idx; j < t[i].n; j++){
//             if(!t[i].N[j]){
//                 t[i].N[j] = 1;
//                 count1++;
//             }
//             if(t[i].N[j]){
//                 count2++;
//             }
//         }
//         cout << count2 - count1 << endl;
//         for(int j = 0; j < t[i].n; j++){
//             cout << t[i].N[j] << " ";
//         }
//         cout << endl;}
//         else cout << 0 << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n, cnt;
int main(){
    int T;
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x == 1) cnt ++;
        }
        cout << cnt << endl;
        for(int i = 1; i <= n; i++){
            cout << "1 ";
        }
    }
    return 0;
}