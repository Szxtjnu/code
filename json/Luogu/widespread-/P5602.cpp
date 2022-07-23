#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    double ans = 0.0;
    long long manzu;
    double baofu = 0.0, temp = 0.0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++){
        manzu += a[i];
        temp = ((manzu*1.0) / (i*1.0))* manzu;
        ans = max(ans, temp);
    }
    printf("%.8f",ans);
    return 0;
}