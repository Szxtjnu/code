#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int L;
double A;
int main()
{
    scanf("%lf%d",&A, &L);
    int ansn, ansd;
    int n = 1, d = 1;
    double min = 99999999,temp;
    while (n <= L && d <= L ){
        temp = A - (double)n / d;
        if(min>fabs(temp)){
            min = fabs(temp);
            ansn = n;
            ansd = d;
        }
        if (temp > 0){
            n++;
        }
        else
            d++;
    }
        printf("%d %d", ansn, ansd);
    return 0;
}