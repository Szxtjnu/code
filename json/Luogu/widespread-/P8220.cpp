#include<bits/stdc++.h>
using namespace std;
int main(){
    long long  n;
    cin >> n;
    long long a, b, c;
    cin >> a >> b >> c;
    if(n>c){
        cout << 2*n-1;
    }
    else{
        long long temp = (b-a) + 1;
        cout << min(2 * n + temp - 1, 2 * c + 1);
    }
    return 0;
}