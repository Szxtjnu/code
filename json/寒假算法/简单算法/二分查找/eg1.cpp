/*输入n(n<=100000)个整数，找出其中的两个数，它们之和
等于整数m(假定肯定有解)。体中所有整数都能用int表示*/

//思路：先排序，然后从a[i]开始向后找是否有m-a[i]

/*思路2：先排序，设置两个变量i和j，i初值0，j初值n-1.
判断a[i]+a[j],如果大于m,就让j -1，如果小于m，就让i +1*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef int ElementType;

void sumofnum1( ElementType a[], int len, ElementType expectsum)
{
    sort(a, a + len - 1);
    for (int i = 0; i < len; i++)
    {
        int L = i + 1, R = len - 1;
        while ( L <= R)
        {
            int mid = L + (R - L) / 2;
            if (a[i] + a[mid] > expectsum)
            {
                R = mid - 1;
            }
            else if (a[i] + a[mid] < expectsum)  
            {
                L = mid + 1;
            }
            else
            {
                cout << a[i] << "\t" << a[mid] << endl;
                break;
            }
        }   
    } 
}
void sumofnum2(ElementType a[],int len, ElementType expectsum)
{
    if (a == NULL || len == 0)
    {
        return;
    }
    sort(a, a + len - 1);
    int L = 0, R = len - 1;
    while (L < R)
    {
        int sum = a[L] + a[R];
        if (sum > expectsum)
        {
            R--;
        }
        else if (sum < expectsum)
        {
            L++;
        }
        else
        {
            cout << a[L] << "\t" << a[R] << endl;
            L++;
            R--;
        }
    }    
}

int main(int argc, char const *argv[] )
{
    int a[] = {2, 4, 6, 1, 0, 8, 10, 3, 5, 12, 14, 16, 18};
    int len = sizeof(a) / sizeof(a[0]);
    //sumofnum1(a, len, 13);
    sumofnum2(a, len, 18);
    return 0;
}