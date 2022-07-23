// #include<iostream>
// #include<cstdio>
// long long ditan[1000][1000] = {-1};
// using namespace std;
// int main() {
//     int n, a, b, g, k;
//     cin >> n;
//     int x1, y1;
//     for(int i = 1; i <= n; i ++){
//         cin >> a >> b >> g >> k;
//         int j, m;
//         for(j = a; j <= a + g; j++){
//             for(m = b; m <= b + k; m++){
//                 ditan[j][m] = i;
//             }
//         }
//     }
//     cin >> x1 >> y1;
//     cout << ditan[x1][y1] << endl;
//     return 0;
// }

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10005], b[10005], g[10005], k[10005];
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
    }
    int x, y;
    cin >> x >> y;
    int j;
    for(j = n; j > 0; j--){
        if(x>=a[j] && y>=b[j] && x<=(a[j]+g[j]) && y<=(b[j]+k[j])){
            cout << j << endl;
            break;
        }
    }
    if(j == 0)  cout << -1;
    return 0;
}