#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>,greater<int> >q;
int n, a, b;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(a == 1){
            scanf("%d", &b);
            q.push(b);            
        }
        if(a == 2){
            int ans = q.top();
            cout << ans << endl;
        }
        if(a == 3){
            q.pop();
        }
    }
    return 0;
}