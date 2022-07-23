#include<bits/stdc++.h>
using namespace std;
struct People
{
    int a;
    string name;
};

int main() {
    int n, m; 
    int idx = 0, x, y;
    cin >> n >> m;
    People P[100005];
    for(int i = 0; i < n; i++){
        cin >> P[i].a >> P[i].name;
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        if((P[idx].a == 0 && x == 0)||(P[idx].a == 1 && x == 1)){
            idx = (n+idx-y)%n;
        }
        else{
            idx = (idx+y)%n;
        }
    }
    cout << P[idx].name << endl;
    // cout << idx;
    return 0;
}