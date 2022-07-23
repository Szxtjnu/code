#include<bits/stdc++.h>
using namespace std;
int main(){
    char a, b;
    int ans[3] = {0};
    while(scanf("%c:=%c;",&a,&b) == 2){
        ans[a-'a']=b>='0' && b<='9' ? b-'0' : ans[b-'a'];
    }
    printf("%d %d %d",ans[0],ans[1],ans[2]);
    return 0;
}