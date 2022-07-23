#include<iostream>
using namespace std;
int BinarySearch( int a[], int size, int p){
    int L = 0;
    int R = size - 1;
    while( L <= R){
        int mid = L + (R - L) / 2;
        if( p == a[mid]){
            return mid ;
        }
        else if( p > a[mid]){
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    return -1;
}

int main()
{
    int a[5], n = 5;
    for(int i=0 ; i<5; i++ )
    {
        cin >> a[i];
    }
    cout << (BinarySearch(a,5,2)+1)  << endl;
    return 0;
}
