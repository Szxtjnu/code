#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
priority_queue<int>q;

int n,a[100005], b[100005], ans[100005];
int main()
{
    scanf("%d",&n);
    int i, j;
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(i=1; i<=n; i++){
        scanf("%d",&b[i]);
    }
    
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            int x = a[i] + b[j];
            if(q.size()<n){
                q.push(x);
            }
            else{
                if(q.top()>x){
                    q.pop();
                    q.push(x);
                }
                else break;
            }
        }
    }
    for(i=n; i>=1; i--) {
        ans[i] = q.top();
        q.pop();
    }
    for(i=1; i<=n; i++){
        printf("%d ",ans[i]);
    }
    return 0;
}