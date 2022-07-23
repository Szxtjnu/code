#include<bits/stdc++.h>
using namespace std;
double a, b, c, d;
double x1, x2, x3;
double cal(double x){
   return a*x*x*x + b*x*x + c*x + d;
}
int main(){
    double l, r, m;
    int s = 0, i;
    cin >> a >> b >> c >> d;
    for(i = -100; i < 100; i++){
        l = i;
        r = i+1;
        x1 = cal(l);
        x2 = cal(r);
        if(!x1){
            printf("%.2lf ",l);;
            s++;
        }
        if(x1 * x2 < 0){
            while((r-l) >= 0.001){
                m = (l+r) / 2;
                if(cal(m)*cal(r) <= 0)
                    l = m;
                else
                    r = m;
            }
            printf("%.2lf ",r);
            s++;
        }
        if(s == 3) break;
    }

    return 0;
}