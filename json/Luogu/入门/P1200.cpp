#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    int temp1 = 1, temp2 = 1;
    for(int i = 0; i < a.length(); i++){
        temp1 *= a[i] - 'A' + 1;
    }   
    for(int i = 0; i < b.length(); i++){
        temp2 *= b[i] - 'A' + 1;
    }   
    temp1 = temp1 % 47;
    temp2 = temp2 % 47;
    if(temp1 == temp2) cout << "GO";
    else cout << "STAY";
    return 0;
}