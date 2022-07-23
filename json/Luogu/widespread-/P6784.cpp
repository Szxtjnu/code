#include<bits/stdc++.h>
using namespace std;
long long a, b, c;
int main(){
    cin >> a >> b >> c;
    long long ans = 0;
    long long temp = 0;
    if(c){    
        if(a < b){
            temp = b - a;
            if(temp <= c){
                c -= temp;
                a = b;
                a += (c/2);
                b += (c/2);
            }
            else{
                a += c;
            }
        }
        else if(a > b){
            temp = a - b;
            if(temp <= c){
                c -= temp;
                b = a;
                a += (c/2);
                b += (c/2);
            }else{
                b += c;
            }
        }
        else{
            a += (c/2);
            b += (c/2);
        }
    }
    while(a > ans && b > ans){
        ans ++;
        a -= ans;
        b -= ans;
    }
    cout << ans;
    return 0;
}