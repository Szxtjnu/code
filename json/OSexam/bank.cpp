int banker_safty_check(int *Available, int Allocation[50][100], int Need[50][100], int procNum, int resNum, int *Seq){
    int i, j, l = 0;
    int Work[100];
    int Finish[50];
    for(i = 0; i < resNum; i++){
        Work[i] = Available[i];
    }
    for(i = 0; i < procNum; i++){
        Finish[i] = 0;
    }

    for(int t = 0; t < procNum; t++){
        for(i = 0; i < procNum; i++){
            if(Finish[i] == 0){
                for(j = 0; j < resNum; j++){
                    if(Need[i][j] > Work[j])
                        break;
                }
                if(j == resNum){
                    Finish[i] == 1;
                    for (int k = 0; k < resNum; k++)
                    {
                        Work[k] = Work[k] + Allocation[i][k];
                    }
                    Seq[l++] = i;
                }
            }
        }
        if(l == procNum){
            // printf("系统是安全的，安全进程序列为：\n");
            for (i = 0; i < l; i++)
            {
                printf("%d", Seq[i]);
                if(i != l - 1)
                    printf("-");
            }
            printf("\n");
            return 1;
        }
    }
    printf("未找到安全进程序列，系统不安全\n");
    return 0;
}

int banker_resource_allocation(int* Available, int Allocation[50][100], int Need[50][100], int Request[50][100], int m, int n, int curPid, int *Seq){
    int i;
    for( i = 0; i < n; i++){
        if(Request[curPid][i] > Need[curPid][i]){
            return 0;//请求资源数超过进程的需求量
        }
        if(Request[curPid][i] > Available[i]){
            return 0;//请求资源数超过系统可用资源量
        }
    }
    for ( i = 0; i < n; i++)
    {
        Available[i] = Available[i] - Request[curPid][i];
        Allocation[curPid][i] = Allocation[curPid][i] + Request[curPid][i];
        Need[curPid][i] = Need[curPid][i] - Request[curPid][i];
    }
    if(banker_safty_check(Available, Allocation, Need, m, n, Seq))
        printf("系统安全");
    else{
        printf("系统不安全");
        for( i = 0; i < n; i++){
            Available[i] = Available[i] + Request[curPid][i];
            Allocation[curPid][i] = Allocation[curPid][i] - Request[curPid][i];
            Need[curPid][i] = Need[curPid][i] + Request[curPid][i];
        }
    }
    return 0;
}