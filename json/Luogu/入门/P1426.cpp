#include<bits/stdc++.h>
using namespace std;
int main(){
    int s, x;
    cin >> s >> x;
    double speed = 7.0, total = 0;
    while(total < (s-x)){
        total += speed;
        speed *= 0.98;
    }
    if(speed >= (x + x + s - total)){
        cout << "n";
    }else
        cout << "y";
    return 0;
}