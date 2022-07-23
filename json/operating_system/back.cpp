#include<bits/stdc++.h>
using namespace std;

void Max(vector<vector<int>>&max, int m, int n){
    cout << "请输入各进程最大需求资源数 按照" << m << "  " << n << 
    "矩阵输入" << endl;

    for (int i = 0; i < m ; i++)
    {
        vector<int> b; //还需要的资源数
        int resource; // 临时变量
        for (int j = 0; j < n; j++)
        {
            cin >> resource;
            b.push_back(resource);
        }
        max.push_back(b);
    }
}

void Allocation(vector<vector<int>>&allocation, const int m, const int n){
    cout << "请输入已分配好的资源数 请按照" << m << "  " << n << "矩阵输入" << endl;
    for (int i = 0; i < m; i++)
    {
        vector<int> b;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        allocation.push_back(b);
    }
}

void Available(vector<int> &available, const int n){
    cout << endl << "请输入每个资源现有的数目" << endl;
    int resource;
    for (int i = 0; i < n; i++)
    {
        cin >> resource;
        available.push_back(resource);
    }
}


void Need(vector<vector<int>>&max, vector<vector<int>>&allocation, vector<vector<int>>&need,int m, int n){
    need.resize(m*n);
    vector<int> t(n,0);
    vector<vector<int>> T(m,t);
    need = T;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int f = max[i][j] - allocation[i][j];
            need[i][j];
            need[i][j] = max[i][j] - allocation[i][j];
        }
        
    }
    
}

void Safe(vector<int> &available, vector<vector<int>>&allocation,
          vector<vector<int>> &need, const int m, const int n){
              while(true){
                  while (true)
                  {
                      vector<int> work = available;
                      vector<bool> Finish(m,false);
                      int mark1 = 0;
                      int mark2 = 0;
                      int mark3 = 0;
                      int *route = new int[m];
                      for (int  z = 0; z < m; z++)
                      {
                          for (int i = 0; i < m; i++)
                          {
                              if(Finish[i] == true){
                                  continue;
                              }
                              mark1 = 0;
                              for (int j = 0; j < n; j++)
                              {
                                  if(work[j] < need[i][j]){
                                      continue;
                                  }
                                  mark1+=1;
                              }
                              if(mark1==n){
                                  Finish[i] = true;
                                  for (int f = 0; f < n; f++)
                                  {
                                      work[f] += allocation[i][f];
                                      allocation[i][f] = 0;
                                      need[i][f] = 0;
                                  }
                                  route[mark3] = i;
                                  mark3+=1;
                              }
                              
                          }
                          
                      }
                    for (int i = 0; i < m; i++)
                    {
                        if(Finish[i] == false){
                            cout << endl << "线程不是安全的";
                            break;
                        }
                        mark2++;
                    }
                    if(mark2 == m){
                        cout << endl << "线程是安全的";
                        cout << endl << "系统的安全序列是" << endl;
                        for (int i = 0; i < m; i++)
                        {
                            if(i == m - 1){
                                cout << route[i];
                                break;
                            }
                            cout << route[i] << "--->";
                        }
                    }
                    int x;
                    cout << endl << "请输入要申请资源的进程号（从0开始，输入小于0结束）" << endl;
                    cin >> x;
                    if(x < 0)
                        break;
                    else{
                        cout << "依次输入各资源所需的数量" << endl;
                        for (int i = 0; i < n; i++)
                        {
                            cin >> need[x][i];
                        }
                    }
                    char judge;
                    cout << "是否请求再次分配Y/N" << endl;
                    cin >> judge;
                    if(judge != 'Y' || judge != 'y'){
                        break;
                    }                    
                      
                  }
                  
              }
          }

int main(){
    int m;
    int n;
    cout << "请输入进程数 :"; 
    cin >> m;
    cout << endl << "请输入资源种类数: ";
    cin >> n;
    vector<vector<int>> max;
    vector<vector<int>> allocation;
    vector<int> available;
    vector<vector<int>> need;
    Max(max,m,n);
    Allocation(allocation,m,n);
    Available(available,n);
    Need(max,allocation,need,m,n);
    Safe(available,allocation,need,m,n);
}