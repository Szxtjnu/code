/*
** FCFS
*/
#include<bits/stdc++.h>
using namespace std;
struct PCB
{
    int arriveTime=0;
    int serveTime=0;
    int runTime=0;
    int endTime=0;
    double turnAroundTime=0;
}p[10];
double total = 0;

void FCFS(PCB *p, int n) {
    for(int i = 0; i < n; i++){
        if((i == 0)||(p[i].arriveTime > p[i-1].endTime)){
            p[i].runTime = p[i].serveTime;
            p[i].endTime = p[i].arriveTime + p[i].serveTime; 
        }else{
            p[i].runTime = p[i].serveTime + p[i-1].endTime -p[i].arriveTime;
            p[i].endTime = p[i].arriveTime + p[i].runTime;
        }
        p[i].turnAroundTime = p[i].runTime*1.0/p[i].serveTime;
        total += p[i].turnAroundTime;
    }
}

int main (){
    int n;
    cout << "input the number of works: ";
    cin >> n;
    cout << endl;
    cout << "input the arrive time and the run time : " << endl;
    for(int i = 0; i < n ; i++){
        cin >> p[i].arriveTime >> p[i].serveTime;
    }
    FCFS(p,n);
    cout << "aver_turnAroundTime : " << total/n*1.0;
}