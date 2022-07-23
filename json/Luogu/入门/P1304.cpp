#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
void cal(int n){
    cout << n << "=";
    for(int i = 2; i < n; i++){
        if(is_prime(i) == true && is_prime(n-i) == true){
            cout << i << "+" << n-i << endl;
            break;
        }
    }    
    
}
int main(){
    int N;
    cin >> N;
    for(int i = 4; i <= N; i += 2){
        cal(i);
    }
    return 0;
}