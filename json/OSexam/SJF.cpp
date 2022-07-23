#include<bits/stdc++.h>
using namespace std;
double sjf_weighted_time(int *arrival_time, int *run_time, int num){
    int time;
    int a;
    int i, j, k;
    double total_time = 0, avg_time;
    // double total_wt = 0, avg_wt;
    // double total_wait = 0, avg_wait;
    typedef struct 
    {
        int arrive;
        int run;
        int finish;
        int wait;
        int total;
    }line;
    line temp, s[100];
    for (i = 0; i < num; i++)
    {
        s[i].arrive = arrival_time[i];
        s[i].run = run_time[i];
    }
    time = s[0].arrive;
    s[0].finish = s[0].run + time;
    s[0].total = s[0].finish - s[0].arrive; 
    // s[0].wait = s[0].finish - s[0].run;
    time += s[0].run;
    for (i = 1; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if(s[j].arrive > time) break;
        }
        a = i;
        for (k = i + 1; k < j; k++)
        {
            if(s[k].run < s[a].run)
                a = k;
        }
        temp = s[i];
        s[i] = s[a];
        s[a] = temp;
        s[i].finish = s[i].run + time;
        s[i].total = s[i].finish - s[i].arrive;
        s[i].wait = s[i].total - s[i].run;
        time += s[i].run;
    }
    for(i = 0; i < num; i++){
        total_time += s[i].total;
        // total_wt += (double)s[i].total / s[i].run;
        // total_wait += s[i].wait;
    }
    avg_time = total_time / num;
    // avg_wt = total_wt / num;
    // avg_wait = total_wait / num;
    return avg_time;
}
