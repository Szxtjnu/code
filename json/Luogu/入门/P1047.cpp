#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    bool a[l+5];
    for(int i = 0; i <= l; i++){
        a[i] = true;
    }
    int b[2*m+5];
    for(int i = 0; i < 2*m; i++)  {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = b[2*i]; j <= (b[2*i]+(b[2*i+1] - b[2*i])); j++){
            a[j] = false;
        }
    }
    int count = 0;
    for(int i = 0; i <= l; i++){
        if(a[i]) count ++;
    }
    cout << count;
    return 0;
}