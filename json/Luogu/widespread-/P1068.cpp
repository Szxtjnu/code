#include<bits/stdc++.h>
using namespace std;
struct NS{
    int l;
    int s;
};
bool cmp(NS x, NS y) { //cmp返回真，则x在y之前，返回假则y在x前
    if(x.s > y.s) return 1;
    if(x.s == y.s && x.l < y.l) return 1;
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    if(m*1.5 > n) exit(0);
    NS ns[10000];
    for(int i = 0; i < n; i++)
        scanf("%d%d",&ns[i].l,&ns[i].s);
    sort(ns, ns+n, cmp);
    int pass = ns[m*3/2-1].s;
    int numOfpeople = 0;
    for(int i = 0; i < n; i++){
        if(ns[i].s >= pass ){
            numOfpeople++;
        }
    }    
    cout << pass << ' ' << numOfpeople << endl;
    for(int i = 0; i < numOfpeople; i++){
        cout << ns[i].l << ' ' << ns[i].s << endl;
    }
    return 0;
}