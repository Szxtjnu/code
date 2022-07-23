#include<bits/stdc++.h>
using namespace std;
int main(){
    double a[50];
    a[1] = 1;
    a[2] = 1;
    int n;
    cin >> n;
    for(int i = 3; i <= 50; i++){
        a[i] = a[i-1] + a[i-2];
    }
    printf("%.2f",a[n]);
    return 0;
}