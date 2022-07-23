#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int temp, num = 0;
    bool flag = false;
    int total = 0;
    while(scanf("%d",&temp) != '\0'){
        for(int i = 0; i < temp; i++){
            if(flag == true)
                cout << "1";
            else cout << "0";
            num ++;
            if(num == n){
                cout << endl;
                num = 0;
            }
        }
        if(flag) flag = false;
        else flag = true;
        total += temp;
        if(total == n * n) break;
    }
    return 0;
}