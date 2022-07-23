#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int apple[15], high, count = 0, derta = 30;
    for( int i = 0; i <10; i++) {
        cin >> apple[i];
    }
    scanf("%d",&high);
    for( int i = 0; i < 10; i++) {
        if((high+derta) >= apple[i])
            count++;
    }
    printf("%d",count);
    return 0;
}