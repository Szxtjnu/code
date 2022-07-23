// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int a[500005], idx[500005];
// int main(){
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         scanf("%d",&a[i]);
//     }
//     for(int i = 0; i < n; i++){
//         int tmp = a[i];
//         for(int j = i+1; j < n; j++){
//             if(tmp > a[j]){
//                 idx[j]++;
//             }
//         }
//     }
//     int total = 0;
//     for(int i = 1; i < n; i++){
//         total += idx[i];
//     }
//     cout << total << endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n, a[5000005], b[5000005];
long long ans;
void merge(int l, int r){
    int mid = (l + r) / 2;
    if(l == r) return;
    merge(l, mid);
    merge(mid+1, r);

    int i = l; int j = mid + 1;
    int t = l;
    while(i <= mid && j <= r){
        if(a[i] > a[j]){
            ans += mid - i + 1;
            b[t++] = a[j];
            ++j;
        }
        else{
            b[t++] = a[i];
            ++i;
        }
    }
    while (i <= mid)
    {
        b[t++] = a[i];
        ++i;
    }
    while (j <= r){
        b[t++] = a[j];
        ++j;
    }
    for(int i = l; i <=r; i++){
        a[i] = b[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    merge(1,n);
    printf("%lld",ans);
    return 0;
}