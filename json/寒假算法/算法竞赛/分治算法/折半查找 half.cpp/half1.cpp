/*题目描述：折半查找
  输入格式：第一行是N，表示有N个元素，第二行是N个数，第三行是M表示要查找的数
  输出格式：一个数，即如找到该数，输出位置，否则输出-1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10001;
int a[MAXN] = {0}, key;

int search(int bot, int top)
{
    int mid;
    if(top>=bot){
        mid = (top + bot) / 2;
        if (key == a[mid]){
            cout << mid << endl;
            return 0;
        }
        else if (a[mid] > key){
            search(bot, mid-1);
        }
        else{
            search(mid + 1, top);
        }
    }
    else{
        cout << "-1" << endl;
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> key;
    search(1, n);
    return 0;
}