#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100005;
int a[MAXN], b[MAXN];
int k, i, j, n;

int main()
{
    void move(int, int);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    move(1, n);
    return 0;
}

void Swap()
{
    swap(a[i], a[j]);
    swap(i, j);
}
void move(int start, int end)
{
    i = start;
    j = end;
    while (i != j)
    {
        if (i < j){
            if (a[i] > a[j])
                Swap();
            else
                --j;
        }
        if (i > j)
        {
            if (a[i] < a[j])
                Swap();
            else
                ++j;
        }
    }
    if (i < k)
        move(i + 1, end);
    else if (i > k)
        move(start, i - 1);
    else{
        for (int l = 1; l <= n; ++l){
            if (b[l] == a[i])
            {
                cout << l << endl;
                break;
            }
        }
    }
}