#include<iostream>
using namespace std;
template <typename T>
void sort( int n, T*& p)
{
    p = new T[n];
    if(p == NULL)
    {
        cout << "动态内存分配失败！" << endl;
        exit(1);
    }
    cout << "请输入要排序的数据" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int temp = 0;
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if(p[j+1]<p[j])
            {
                temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
            }
        }
    }
}
int main()
{
    int n = 0;
    cout << "请输入所要排序的数据个数：" << endl;
    cin >> n;
    int *p;
    sort(n, p);
    for (int i = 0; i < n; ++i)
    {
        cout << p[i] << "  ";
    }
    cout << endl;
    delete[] p;
    return 0;
}
