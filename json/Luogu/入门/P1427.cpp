#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        s.push(n);
    }
    while(!s.empty()){
        cout<< s.top() << " ";
        s.pop();
    }
    return 0;
}