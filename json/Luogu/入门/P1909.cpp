#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Pen
{
    int total;
    int num;
    int price;
};
bool cmp(Pen x, Pen y){
    return x.total > y.total;
}
int main() {
    int n;
    Pen pen[3];
    scanf("%d", &n);
    for(int i = 0; i < 3 ; ++i){
        scanf("%d%d",&pen[i].num, &pen[i].price);
    }
    for(int i = 0; i < 3; ++i)  {
        if(n%pen[i].num != 0){
            pen[i].total = ((n / pen[i].num) + 1)* pen[i].price;
        }
        else{
            pen[i].total = (n / pen[i].num) * pen[i].price;
        }
    }
    sort(pen, pen+3, cmp);
    cout << pen[2].total;

    return 0;
}
