#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, Na, Nb, suma = 0, sumb = 0;
    int v[5][5] = {{0,0,1,1,0}, {1,0,0,1,0}, {0,1,0,0,1},{0,0,1,0,1}, {1,1,0,0,0}};
    int A[205], B[205];
    cin >> N >> Na >> Nb;
    for(int i = 0; i < Na; i++) scanf("%d",&A[i]);
    for(int i = 0; i < Nb; i++) scanf("%d",&B[i]);
    for(int i = 0; i < N; i++){
        suma += v[A[i%Na]][B[i%Nb]];
        sumb += v[B[i%Nb]][A[i%Na]];
    }
    cout << suma << " " << sumb << endl;
    return 0;
}