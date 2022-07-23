// @version 1.0
// #include<bits/stdc++.h>
// using namespace std;
// struct Player{
//     int score;
//     int strength;
//     int idx;
// };
// bool cmp(Player p1, Player p2){
//     if(p1.score == p2.score) return p1.idx < p2.idx;
//     else return p1.score > p2.score;
// }
// int main() {
//     int N, R, Q;
//     cin >> N >> R >> Q;
//     int n = 2 * N;
//     Player p[n];
//     for(int i = 0; i < n; i++){
//         scanf("%d",&p[i].score);
//     }
//     for(int i = 0; i < n; i++){
//         scanf("%d",&p[i].strength);
//         p[i].idx = i + 1;
//     }
//     sort(p,p+n,cmp);
//     for(int i = 0; i < R; i++){
//         for(int j = 0; j < n; j += 2){
//             if(p[j].strength > p[j+1].strength)
//                 p[j].score ++;
//             else p[j+1].score ++;
//         }
//         sort(p,p+n,cmp);
//     }
//     cout << p[Q-1].idx << endl;
//     return 0;
// }

// @version 2.0 merge
#include<bits/stdc++.h>
using namespace std;
#define maxn 200100
struct Player{
    int grade;
    int num;
};
Player a[maxn];
Player A[100001];
Player B[100001];
int w[maxn];
bool cmp(Player p1, Player p2)  {
    if(p1.grade == p2.grade) return p1.num < p2.num;
    return p1.grade > p2.grade;
}
int n, r, q;
void MergerSort(){
    int i, j, k;
    i = j = k = 1;
    while (i <= n && j <= n)
    {
        if(A[i].grade > B[j].grade || (A[i].grade ==B[j].grade && A[i].num < B[j].num)){
            a[k].grade = A[i].grade;
            a[k++].num = A[i++].num;
        }else {
            a[k].grade = B[j].grade;
            a[k++].num = B[j++].num;
        }
    }
    while (i<=n)
    {
        a[k].grade = A[i].grade;
        a[k++].num = A[i++].num;

    }
    while (j<=n)
    {
        a[k].grade = B[j].grade;
        a[k++].num = B[j++].num;
    }
}
int main(){
    cin >> n >> r >> q;
    for (int i = 1; i <= 2*n; i++)
    {   
        cin >> a[i].grade;
        a[i].num = i;
    }
    for (int  i = 1; i <= 2*n; i++)
    {
        cin >> w[i];
    }
    sort(a+1,a+1+2*n,cmp);
    for(int k = 1; k <= r; k++){
        int tt = 1;
        for(int i = 1; i < 2*n; i+=2){
            if(w[a[i].num]>w[a[i+1].num]){
                A[tt].grade = a[i].grade + 1;
                A[tt].num = a[i].num;
                B[tt].grade = a[i+1].grade;
                B[tt].num = a[i+1].num;
                tt++;
            }else{
                A[tt].grade = a[i+1].grade + 1;
                A[tt].num = a[i+1].num;
                B[tt].grade = a[i].grade;
                B[tt].num = a[i].num;
                tt++;
            }
        }
        MergerSort();
    }
    cout << a[q].num << endl;
    return 0;
}