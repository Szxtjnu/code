## 寒假算法记录 ##
---
![th.jpg](https://www.tsinghua.edu.cn/images/20/04/29/263mcc6ojy/jiasuomenkou.jpg)
---
### 近似整数 Approximation.cpp POJ1650
#### 题目描述：
> 给定一个浮点数A和一个整数L，求在范围[1,L]内的两个整数n和d，使得n和d能近似等于A，且使误差|A-n/d|最小。
#### 输入格式：
> 一行两个数：浮点数A,整数L。数据保证有解。
#### 输出格式：
> 一行两个整数n和d
#### 输入样例：
> 3.14159265358979
> 10000
#### 输出样例：
> 355 113
---
#### _题目分析_：
 ![s2IZ1P.jpg](https://s3.ax1x.com/2021/01/19/s2IZ1P.jpg)
 ---
 #### 代码：
 ``` cpp
 #include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int L;
double A;
int main()
{
    scanf("%lf%d",&A, &L);
    int ansn, ansd;
    int n = 1, d = 1;
    double min = 99999999,temp;
    while (n <= L && d <= L ){
        temp = A - (double)n / d;
        if(min>fabs(temp)){
            min = fabs(temp);
            ansn = n;
            ansd = d;
        }
        if (temp > 0){
            n++;
        }
        else
            d++;
    }
        printf("%d %d", ansn, ansd);
    return 0;
}
```