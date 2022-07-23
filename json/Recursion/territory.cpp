#include<bits/stdc++.h>
using namespace std;
int ans;
int z(int a, int b){
    if(a == b) return 1;
    else if(a < b){
        b = b - a;
        ans = z(a, b) + 1;
        return ans;
    }
    else{
        a = a - b;
        ans = z(a, b) + 1;
        return ans;
    }
}
int main(){
    int x, y;
    cin >> x >> y;
    cout << z(x, y) << endl;
    return 0;
}