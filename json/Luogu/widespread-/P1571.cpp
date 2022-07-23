#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int n, m;
bool binary_search(int x){
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if(b[mid] == a[x]) return 1;
        if(b[mid - 1] < a[x] && b[mid + 1] > a[x]) return 0;
        if(b[mid] > a[x]) r = mid;
        else l = mid + 1;
    }
    return 0;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d",&b[i]);
    }
    sort(b+1, b+1+m);
    for(int i = 1; i <= n; i++){
        if(binary_search(i)){
            printf("%d ", a[i]);
        }
    }
    return 0;
}