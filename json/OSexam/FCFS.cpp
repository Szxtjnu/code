double fcfs_turnaround_time(int *arrival_time, int *run_time, int num){
//填入自己的代码
    int end_time[100];
    int zz_time[100];
    // int wait_time[100];
    // double dqzz_time[100];
    double total_time, avg_time;
    // double total_wt, avg_wt;
    // double total_wait, avg_wait;
    for(int i = 0; i < num; i++){
        if(i==0){
            end_time[i] = arrival_time[i] + run_time[i];
        }
        else{
            end_time[i] = end_time[i-1] + run_time[i];
        }
        zz_time[i] = end_time[i] - arrival_time[i];
        // wait_time[i] = zz_time[i] - run_time[i];
        // dqzz_time[i] = (double)zz_time[i] / run_time[i];
    }
    total_time = 0.0;
    // total_wt = 0.0;
    // total_wait = 0.0;
    for(int i = 0; i < num; i++){
        total_time += zz_time[i];
        // total_wt += dqzz_time[i];
        // total_wait += wait_time[i];
    }
    avg_time = total_time / num;
    // avg_wt =  total_wt / num;
    // avg_wait = total_wait / num;
    return avg_time;
}