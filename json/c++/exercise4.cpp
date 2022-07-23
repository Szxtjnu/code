#include<iostream>
using namespace std;
template <typename T>
int BiFind(T a[], int n, T val)
{
    int ed = n - 1, st = 0;
    while(ed>=st)
    {
        cout << st << "     " << ed << endl;
        int idx =( (st + ed) / 2);
        if(a[idx]==val)
        {
            return idx;
        }
        if(a[idx]>val)
            ed = idx - 1;
        else if(a[idx] < val)
            st = idx + 1;
    }
    return (-1);
}
int main()
{
    int a[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int val = 4;
    int n = 10;
    cout << BiFind(a, n, val);
    return 0;
}
