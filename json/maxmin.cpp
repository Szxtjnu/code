//
//  main.cpp
//  EditDistance
//
//  Created by Alan On 10/21/2021.
//
 
#include <iostream>
using namespace std;
void getMaxAndMinValue(int a[], int low, int high, int &maxValue, int &minValue)
{
    if(low == high)
    {
        maxValue = a[low];
        minValue = a[high];
        return;
    }
    if(low + 1 == high)
    {
        if (a[low] > a[high]) {
            maxValue = a[low];
            minValue = a[high];
        }
        else
        {
            maxValue = a[high];
            minValue = a[low];
        }
        return;
    }
    int lmax;
    int lmin;
    int rmax;
    int rmin;
    int mid = (low + high) / 2;
    getMaxAndMinValue(a, low, mid - 1, lmax, lmin);
    getMaxAndMinValue(a, mid, high, rmax, rmin);
    if(lmax > rmax){
        maxValue = lmax;
    }
    else{
        maxValue = rmax;
    }
    if (lmin > rmin) {
        minValue = rmin;
    }
    else{
        minValue = lmin;
    }
    
}
int main()
{
 
    int maxValue, minValue;
    int a[] = {12, 324, 23, -12, 8, 9, 1213, 56, 28};
    getMaxAndMinValue(a, 0, 8, maxValue, minValue);
    cout << maxValue << " " << minValue << endl;
    return 0;
}