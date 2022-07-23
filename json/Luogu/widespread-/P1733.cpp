#include<bits/stdc++.h>
using namespace std;
int main(){
    int mid;
    int l, r;
    int echo;
    for(l = 1, r = 1e9, mid = (l+r) >> 1; l <= r; mid = (l+r) >> 1){
        cout << mid << endl;
        cin >> echo;
        if(echo == 0){
            return 0;
        } else if(echo == -1){
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    return 0;
}