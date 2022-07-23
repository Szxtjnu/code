#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1000010;
int a[MAXN], b[MAXN];

int main()
{
    int search(int, int, int, int, int);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int  i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    printf("%d", search(0, n - 1, 0, m - 1, k));
    return 0;
}
 
int search(int s1, int e1, int s2, int e2, int kth)
{
    int idxA = (s1 + e1) / 2;
    int idxB = (s2 + e2) / 2;
    int lenA = idxA - s1 + 1;
    int lenB = idxB - s2 + 1;
    if (s1 > e1){
        lenA = 0;
    }
    if (s2 > e2){
        lenB = 0;
    }
    int len = lenA + lenB;
    if (len > kth){
        if (0 != lenB && (0 == lenA || a[idxA] <= b[idxB])){
            return search(s1 , e1, s2, idxB - 1, kth);
        }
        else
            return search(s1, idxA - 1, s2, e2, kth);
    }
    else{
        if (kth == len){
            if (lenA == 0){
                return b[idxB];
            }
            else if (lenB == 0){
                return a[idxA];
            }
        }
        if (0 != lenA && (0 == lenB || a[idxA] <= b[idxB]))
            return search(idxA + 1, e1, s2, e2, kth - lenA);
        else
            return search(s1, e1, idxB + 1, e2, kth - lenB);
    }
}