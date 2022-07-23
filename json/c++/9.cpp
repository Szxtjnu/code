#include<iostream>
using namespace std;
const int n = 3;
int a[n][n];
int main()
{
    int max[5], min[5], t = 0;
    for (int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            max[i] = a[i][0];
            if(a[i][j] > max[i])
                max[i] = a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            min[j] = a[0][j];
            if(a[i][j] < min[j])
                min[j] = a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (max[i] == min[j])
            {
                t++;
                cout << "鞍点:" << max[i];
            }
        }
    if (t == 0)
        cout << "无鞍点" << endl;
    return 0;
}