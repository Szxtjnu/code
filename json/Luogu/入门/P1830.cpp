#include<bits/stdc++.h>
using namespace std;
struct dian{
    int a;
    int b;
};
dian d[105][105];
int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            d[i][j].a = 0;
            d[i][j].b = 0;
        }
    }
    for(int i = 1; i <= x; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <= x2; j++){
            for(int k = y1; k <= y2; k++){
                d[j][k].a = i;
                d[j][k].b ++;
            }
        }
    }
    dian dd[100];
    for(int i = 1; i <= y; i++){
        int xx, yy;
        cin >> xx >> yy;
        dd[i].a = xx;
        dd[i].b = yy;
    }
    for(int i = 1; i <= y; i++){
        if(!d[dd[i].a][dd[i].b].a){
            cout << "N" << endl;
        }else{
            cout << "Y " << d[dd[i].a][dd[i].b].b
            << " " << d[dd[i].a][dd[i].b].a << endl;
        }
    }
    return 0;
}