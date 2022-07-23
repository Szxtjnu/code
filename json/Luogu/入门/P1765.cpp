#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5] = {0,1,2,3,4};
    string s;
    int ans = 0;
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='a'||s[i]=='d'||
        s[i]=='g'||s[i]=='j'||
        s[i]=='m'||s[i]=='p'||
        s[i]=='t'||s[i]=='w') ans += 1;
        if(s[i]=='b'||s[i]=='e'||
        s[i]=='h'||s[i]=='k'||
        s[i]=='n'||s[i]=='q'||
        s[i]=='u'||s[i]=='x') ans += 2;
        if(s[i]=='c'||s[i]=='f'||
        s[i]=='i'||s[i]=='l'||
        s[i]=='o'||s[i]=='r'||
        s[i]=='v'||s[i]=='y') ans += 3;
        if(s[i]=='s'||s[i]=='z') ans += 4;
        if(s[i] == ' ') ans++;
    }
        
    cout << ans;
    return 0;
}