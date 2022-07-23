#include <bits/stdc++.h>
using namespace std;
struct PCB
{
    string name;
    int arriveTime = 0;
    int runTime = 0; //
    int startTime = 0;
    int finishTime = 0;
    bool flag;
};
bool cmp(PCB p1, PCB p2)
{
    if (p1.arriveTime <= p2.arriveTime)
    {
        return true;
    }
    else
        return false;
}
bool cmp2(PCB p1, PCB p2)
{
    if (p1.startTime <= p2.startTime)
    {
        return true;
    }
    else
        return false;
}
void SJF(PCB *p, int n)
{
    sort(p, p + n, cmp);
    int finishALL = 0;
    int CurrentTime = 0;
    int i = 0;
    while (finishALL < n)
    {
        if (CurrentTime > p[0].arriveTime && finishALL == 0)
        {
            CurrentTime = p[0].arriveTime;
            p[0].startTime = p[0].arriveTime;
            p[0].finishTime = CurrentTime + p[0].runTime;
            CurrentTime = CurrentTime + p[0].runTime;
            p[0].flag = true;
            finishALL++;
            i++;
        }
        else if (CurrentTime > p[i].arriveTime && finishALL > 0)
        {
            int num = 0;
            int temp;
            for (int j = 0; j < n; j++)
            {
                if (p[j].flag == true)
                    continue;
                if (CurrentTime >= p[j].arriveTime)
                {
                    num++;
                    temp = j;
                }
            }
            if (num == 1)
            {
                p[temp].startTime = CurrentTime;
                p[temp].finishTime = CurrentTime + p[temp].runTime;
                p[temp].flag = true;
                finishALL++;
                i++;
            }
            else if (num > 1)
            {
                int minProcess = 0;
                for (int k = 0; k < n; k++)
                {
                    if (p[k].flag)
                        continue;
                    else
                    {
                        if (p[k].runTime < p[minProcess].runTime)
                        {
                            minProcess = k;
                        }
                    }
                }
                p[minProcess].startTime = CurrentTime;
                p[minProcess].finishTime = CurrentTime + p[minProcess].runTime;
                CurrentTime = p[minProcess].finishTime;
                p[minProcess].flag = true;
                finishALL++;
            }
        }
        else
        {
            CurrentTime++;
        }
    }
}

int main()
{
    int n = 5;
    // cout << "input the number of works: ";
    // cin >> n;
    // cout << endl;
    // cout << "input the name of process,the arrive time and the run time : " << endl;
    // for(int i = 0; i < n ; i++){
    //     cin >> p[i].name >> p[i].arriveTime >> p[i].runTime;
    // }
    PCB p[n] = {{"P1", 5, 7},
                {"P2", 4, 4},
                {"P3", 3, 1},
                {"P4", 2, 4},
                {"P5", 1, 5}};

    SJF(p, n);
    sort(p, p + n, cmp2);
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "  " << p[i].startTime << "   " << p[i].finishTime
             << endl;
    }
}