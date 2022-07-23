#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double ans, b, c;
    cin >> n;
    if(n <= 150){
        ans = 0.4463 * (n * 1.0);
    }else if(n > 150 && n <= 400){
        ans = 0.4463 * (150 * 1.0) + 0.4663 * ((n-150) * 1.0);
    }else{
        ans = 0.4463 * (150 * 1.0) + 0.4663 * ((400-150) * 1.0) + 0.5663 * ((n-400) * 1.0);
    }
    printf("%.1f",ans);
    return 0;
}