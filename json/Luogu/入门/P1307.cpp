#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main() {
    int n;
    queue<int>s;
    cin >> n;
    if(n == 0){ cout << "0"; exit(0);} 
    bool flag, idx = true;
    if(n<0) {
        flag = true;
        n = -n;
    }
    else flag = false;
    while(n!=0){
        s.push(n%10);
        n/=10;
    }
    if(flag){
        cout << "-";
    }
    while(!s.empty()){
        if(s.front()==0 && idx){s.pop();}
        else{
            cout << s.front();
            s.pop();
            idx = false;}
    }
    return 0;
}