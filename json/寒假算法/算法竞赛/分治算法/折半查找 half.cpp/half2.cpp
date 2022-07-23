/*题目描述：折半查找
  输入格式：第一行是N，表示有N个元素，第二行是N个数，第三行是M表示要查找的数
  输出格式：一个数，即如找到该数，输出位置，否则输出-1
  非递归算法
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 10001;
int a[MAXN] = {0}, top, bot, key, n;
void half()
{
    int bot = 1;
    int top = n;
    int mid;
    while (bot <= top){
        mid = bot + (top - bot) / 2;
        if(a[mid]==key){
            cout << mid << endl;
            exit(0);
        }
        else if (a[mid] > key){
            top = mid - 1;
        }
        else
            bot = mid + 1;
    }

    cout << -1 << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> key;
    if(key<a[1]||key>a[n])
        cout << -1 << endl;
    else
    half();
    return 0;
}