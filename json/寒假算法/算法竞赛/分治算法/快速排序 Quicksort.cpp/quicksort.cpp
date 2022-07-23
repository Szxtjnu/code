#include<iostream>
using namespace std;
int a[10];
void sort(int l, int r)
{
    int i, j,mid,temp;
    i = l;
    j = r;
    mid = (i + j) / 2;
    do
    {
    while(a[i]<a[mid])
        i++;
    while(a[j]>a[mid])
        j--;
    if(i<=j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    } while (i <= j);
    if (l < j)
        sort(l, j);
    if (i < r)
        sort(i, r);
}
int main()
{
    for (int i = 0; i < 10; ++i){
        cin >> a[i];
    }
    sort(0, 9);
    for (int i = 0; i < 10; ++i){
        cout << a[i];
        cout << " ";
    }
    return 0;
}