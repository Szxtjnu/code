## 寒假算法记录 

---
![](https://img.imgdb.cn/item/60113c703ffa7d37b322b4a0.jpg)
---

### 循环比赛日程表 match.cpp

#### 题目描述：
>设有n=2^m个运动员，要进行网球循环赛。现在要设计一个满足以下要求的比赛日程表

>（1）.每个选手必须与其他n-1个选手各赛一场

>（2）.每个选手一天只能赛一次

>（3）.循环赛一共进行n-1天
#### 输入格式：
> m
#### 输出格式：
> 表格形式的比赛安排表
#### 输入样例：
> 3
#### 输出样例：

> | |第一天|第二天|第三天|第四天|第五天|第六天|第七天|
> |-|-|-|-|-|-|-|-|
> |1|2|3|4|5|6|7|8|
> |2|1|4|3|6|5|8|7|
> |3|4|1|2|7|8|5|6|
> |4|3|2|1|8|7|6|5|
> |5|6|7|8|1|2|3|4|
> |6|5|8|7|2|1|4|3|
> |7|8|5|6|3|4|1|2|
> |8|7|6|5|4|3|2|1|

---

#### _题目分析_：
从表格就可以看出这是一个有对称性的表格

![](https://img.imgdb.cn/item/600944f63ffa7d37b362d9a6.png)

---

### 代码示例:
``` cpp
#include<iostream>
#include<cmath>
const int MAXN = 1025;
int a[MAXN][MAXN];
using namespace std;
int main()
{
    int m, half = 1;
    cin >> m;
    int n = pow(2,m);
    int k = 1;
    a[0][0] = 1;
    while (k <= m)
    {
        for (int i = 0; i < half; ++i){
            for (int j = 0; j < half; ++j){
                a[i][j + half] = a[i][j] + half;
            }
        }
        for (int i = 0; i < half; ++i)
            for (int j = 0; j < half; ++j)
            {
                a[i + half][j] = a[i][j + half];
                a[i + half][j + half] = a[i][j];
            }
        half *= 2;
        ++k;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", a[i][j]);
        }
        cout << '\n';
        }
        return 0;
}
```