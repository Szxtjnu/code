#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int n, week, total = 0;
    int we[7] = {250,250,250,250,250,0,0};
    cin >> week >> n;
    int i = week - 1;
    while(n > 0) {
        total += we[i];
        i++;
        i = i % 7;
        n--;
    }
    cout << total;
    return 0;
}