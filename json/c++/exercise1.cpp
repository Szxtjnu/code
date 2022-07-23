#include<iostream>
using namespace std;
template <class T>
T Min(T A[], int n)
{
    T temp;
    temp = A[0];
    for (int i = 0; i < n; ++i)
    {
        if(A[i]<temp)
        {
            temp = A[i];
        }
    }
    return temp;
}

int main()
{
    int a[10] = {0, 1, 2, 3, 4, -6, 5, -3, 2, 10};
    cout << Min(a, 10) << endl;
    return 0;
}