#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    char a[20];
    int b[10] = {0};
    for(int i = 0; i < 13; i++){
        cin >> a[i];
    }
    int j = 0;
    for(int i = 0; i < 13; i++) {
        if(a[i]!='-') {
            b[j] = a[i] - '0';
            j++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 9; i++){
        ans += b[i] * (i+1);
    }
    if((ans % 11) != 10) {
        if((ans % 11) == b[9]){
            cout << "Right";
        }
        else{
            b[9] = ans%11;
            for(int i = 0; i < 12; i++){
                cout << a[i];
            }
            printf("%c", (b[9]+'0'));
        }
    }
    if((ans % 11) == 10){
        if(a[12] == 'X'){
            cout << "Right";
        }
        else{
            a[12] = 'X';
            for(int i = 0; i < 13; i++){
                cout << a[i];
            }
        }
    }
    return 0;
}