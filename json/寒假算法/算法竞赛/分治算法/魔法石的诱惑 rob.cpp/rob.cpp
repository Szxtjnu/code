#include<iostream>
#include<cstdio>
using namespace std;

int solve(int n)
{
    int ans = 0;
    while (n>0)
    {
        ans += n / 5;
        n = n / 5;
    }
    return ans;
}

int main()
{
    int Q;
    scanf("%d", &Q);
    int start = 1;
    int end = 500000000;
    int ans = 500000001;
    int mid;
    int t;
    while(start<=end){
        mid = start + (end - start) / 2;
        t = solve(mid);
        if (t == Q && mid < ans){
            ans = mid;
        }
        if (t > Q){
            end = mid - 1;
        }
        else if (t < Q){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    if(ans != 500000001){
        printf("%d", ans);
    }
    else{
        cout << "No solution." << endl;
    }
    return 0;
}