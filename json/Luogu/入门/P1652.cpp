#include<bits/stdc++.h>
using namespace std;
int n;
int x[1010], y[1010], r[1010];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1; i <= n; i++)
        cin >> y[i];
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    int x1,x2,y1,y2;
    int ans = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n; i++){
        if((sqrt((x1-x[i])*(x1-x[i]) + (y1-y[i])*(y1-y[i])) < r[i])
        ^(sqrt((x2-x[i])*(x2-x[i]) + (y2-y[i])*(y2-y[i])) < r[i]))
        ans ++;
    }
    cout << ans;
    return 0;
}