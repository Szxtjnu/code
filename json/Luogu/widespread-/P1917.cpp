#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[3][3];
    string b;
    int ans = 0;
    for(int i = 0; i < 3; i++){
        getline(cin,b);
        for(int j = 0; j < b.length(); j++){
            a[i][j] = b[j];
            if(b[j]=='X'||b[j]=='O') ans ++;
        }
    }
    if(a[0][0] == 'X'||a[0][2] == 'X'||
    a[2][0] == 'X'||a[2][2] == 'X'||ans <= 1){
        cout << "Dont know." << endl;
        cout << ans;
    }else{
        cout << "xiaoa will win." << endl;
        cout << ans;
    }

    return 0;
}