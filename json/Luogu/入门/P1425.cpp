#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d, temp;
    cin >> a >> b;
    cin >> c >> d;
    temp = (c*60 + d) - (a*60 + b);
    cout << temp/60 << " " << temp%60;
    return 0;
}