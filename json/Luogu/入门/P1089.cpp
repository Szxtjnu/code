#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    static int mMoney;
    static int tmp = 0;
    int a[15];
    for(int i = 1; i <= 12; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= 12; i++){
        tmp += 300;
        tmp = tmp - a[i];
        if(tmp < 0 )   {
            cout << "-" << i << endl;
            exit(0);
        }
        else if(tmp >= 100){
            mMoney += (tmp / 100) * 100;
            tmp -=((tmp/100) * 100);
        }
    }
    cout << (mMoney*1.2+tmp);
    return 0;
}