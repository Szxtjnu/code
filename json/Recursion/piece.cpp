#include<bits/stdc++.h>
using namespace std;

void move(int k){
    if(k == 4){
        cout << "4,5-->9,10" << endl;
        cout << "8,9-->4,5" << endl;
        cout << "2,3-->8,9" << endl;
        cout << "7,8-->2,3" << endl;
        cout << "1,2-->7,8" << endl;
    }
    else {
        cout << k << "," << k+1 << "-->" << 2*k+1 << "," << 2*k+2 << endl;
        cout << 2*k << "," << 2*k-1 << "-->" << k << "," << k+1 << endl;
        move(k-1);
    }
    return ;
}

int main(){
    int N = 0;
    while (N < 4)
    {
        cin >> N;
    }
    move(N);
    return 0;
}