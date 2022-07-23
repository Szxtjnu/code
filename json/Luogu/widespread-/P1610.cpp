#include<bits/stdc++.h>
using namespace std;
int A[100005];
int main(){
    int n, dist, count = 0;
    cin >> n >> dist;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A+n);
    for(int i = 1; i < n-1; i ++){
        if(A[i+1] - A[i-1] <= dist){
            A[i] = A[i-1];
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}