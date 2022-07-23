#include<bits/stdc++.h>
using namespace std;
int main(){
    string l;
    cin >> l;
    int boy = 0, girl = 0;
    for(int i = 0; i <= l.length(); i++){
        if(l[i] == 'b' || l[i+1] == 'o' || l[i+2] == 'y')
            boy ++;
        if(l[i] == 'g' || l[i+1] == 'i' || l[i+2] == 'r' || l[i+3] == 'l')
            girl ++; 
    }
    cout << boy << endl;
    cout << girl << endl;
    return 0;
}