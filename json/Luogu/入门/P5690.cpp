#include<bits/stdc++.h>
using namespace std;
int b[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int m, d;
    char a;
    int ans = 0;
    cin >> m >> a >> d;
    if(d>0 && d<=28){
        if(m>0 && m<=12) cout << 0;
        else cout << 1;
    }else if(d==29||d==30){
        if(m==2||m==0||m>12) cout << 1;
        else cout << 0;
    }else if(d==31){
        if(m==2||m==4||m==6||m==9||m==11||m>12&&m<20) cout <<1;
        else if(m==1||m==3||
            m==5||m==7||
            m==10||m==8||
            m==12) cout << 0;
        else if(m%10==4||m%10==6||m%10==9) cout << 2;
        else cout << 1;
    }else if(m==0||m>12) cout << 2;
    else cout << 1;

    return 0;
}