#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int avgGrade;
    int classGrade;
    char leader;
    char westStudent;
    int numOfpaper;
    int total = 0;
    int idx;
};
bool cmp(Student s1, Student s2){ //奖学金数从大到小排序，相同时按序号数从小到大排序
    if(s1.total == s2.total) return s1.idx < s2.idx;
    else return s1.total > s2.total;
}
int main() {
    Student s[101];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i].name >> s[i].avgGrade >> s[i].classGrade
        >> s[i].leader >> s[i].westStudent >> s[i].numOfpaper;
    }
    int totalOfnum = 0;
    for(int i = 0; i < N; i++){
        if(s[i].avgGrade > 80 && s[i].numOfpaper >= 1) s[i].total +=8000;
        if(s[i].avgGrade > 85 && s[i].classGrade > 80) s[i].total +=4000;
        if(s[i].avgGrade > 90 ) s[i].total +=2000;
        if(s[i].avgGrade > 85 && s[i].westStudent == 'Y' ) s[i].total +=1000;
        if(s[i].classGrade > 80 && s[i].leader == 'Y' ) s[i].total +=850;
        totalOfnum += s[i].total;
        s[i].idx = i;
    }
    sort(s,s+N,cmp);
    cout << s[0].name << endl;
    cout << s[0].total << endl;
    cout << totalOfnum << endl;
    return 0;
}