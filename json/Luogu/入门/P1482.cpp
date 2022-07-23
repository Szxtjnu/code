#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(!b) return a;
    else return gcd(b,a%b);
}
int main(){
    int a1, a2, b1, b2;
    char spc;
    scanf("%d",&a1);
    spc = getchar();
    scanf("%d",&b1);
    scanf("%d",&a2);
    spc = getchar();
    scanf("%d",&b2);
    int c1 = a1*a2, c2 = b1*b2;
    int t = gcd(c1,c2);
    c1 /= t;
    c2 /= t;
    printf("%d %d\n",c2,c1);
    
    return 0;
}