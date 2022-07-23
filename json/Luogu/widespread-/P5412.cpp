#include<bits/stdc++.h>
using namespace std;
struct student
{
    bool sex;
    double high;
};
student s[10005];
bool cmp(student s1, student s2){
    if(s1.high < s2.high) return 1;
    else return 0;
}
int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> s[j].sex;
        }
        for(int j = 1; j <= n; j++){
            cin >> s[j].high;
        }
        sort(s+1,s+1+n,cmp);
        for(int j = 1; j <= n; j++){
            if(!s[j].sex){
                cout << s[j].high << " ";
            }
        }
        cout << endl;
        for(int j = 1; j <= n; j++){
            if(s[j].sex){
                cout << s[j].high << " ";
            }
        }
    }
    return 0; 
}