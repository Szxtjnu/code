寒假算法记录 

---
![](https://img.imgdb.cn/item/60129c713ffa7d37b3d8737b.jpg)

---

### 残缺棋盘问题 chessboard.cpp
#### 题目描述：
> &#8195;残缺棋盘是一个有 $2^{k}×2^{k}$ ($1<k<10$) 个方格的棋盘，其中恰有一个方格残缺，如下图所示。
>
>![](https://img-blog.csdnimg.cn/20200204143945742.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9hbHRsaS5ibG9nLmNzZG4ubmV0,size_16,color_FFFFFF,t_70)
>
> &#8195;图中黑色的部分假定是残缺的部分。
> 
> &#8195;残缺棋盘的问题要求用三格板覆盖残缺棋盘。在此覆盖中两个三格板不能重叠，三格板不能覆盖残缺方格，但必须覆盖其他所有的方格。下图就是四种方向的三格板。
>
>![](https://img-blog.csdnimg.cn/20200204144121488.png)
>
> &#8195;就是要用这四种形状的来覆盖其他的方格。
> 
> 假定a形用1表示，b形用2表示……
#### 输入格式：
> &#8195;三个整数，即k和坏格子的坐标x和y;
#### 输出格式：
> &#8195;数字方阵，其中坏坐标以数字7来表示；
#### 输入样例：
> 2 1 1
#### 输出样例：
> 7 4 2 2
>
> 4 4 4 2
>
> 3 4 4 4
>
> 3 3 4 4

---

#### _题目分析_：
&#8195;首先先分析题意。有一格是残缺的，用另外四种类型的纸片遮住剩下的格子。我们仔细观察就可以发现，题目中给出的四种形状是当k取1的时候，除了残缺的那部分剩下的图像。所以当k等于1的时候，用哪种形状就显而易见。

&#8195;那么这个假设能不能推广到k=2的时候呢？当k=2的时候，正方形是由4*4总共16个小正方形构成的，我们把每2\*2个小正方形看作是一个小正方形，那么如果缺失了的正方形在左上角，那么我们就用d形状的纸片。

![](https://img-blog.csdnimg.cn/20200204145150460.png)

&#8195;就像这样，然后在去每个2*2的小正方形里判断应该用哪种形状遮盖。

&#8195;这样，我们就把 $2^k×2^k$ 的残缺棋盘分成了4个 $2^{k-1}×2^{k-1}$ 的残缺棋盘，当k等于1的时候，我们就能很轻松的判断出应该用什么了。

---

代码：
``` cpp
#include<iostream>
#include<cstdio>
using namespace std;
int k = 1, c[1024][1024];

void lt(int x1, int y1, int x2, int y2)//左上
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 4;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 4;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 4;
}

void lb(int x1, int y1, int x2, int y2)//左下
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 2;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 2;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 2;
}

void rt(int x1,int y1,int x2,int y2)//右上
{
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 3;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 3;
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2 + 1] = 3;
}

void rb(int x1,int y1,int x2,int y2)//右下
{
    c[x1 + (x2 - x1) / 2 + 1][y1 + (y2 - y1) / 2] = 1;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = 1;
    c[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2 + 1] = 1;
}

void cover(int x1, int y1, int x2, int y2)//覆盖函数
{
    int i, j, p =1, q =1;
    if (x2 - x1 == 1) //如果k=1的时候填充并结束
    {
        for (i = x1; i <= x2; ++i)
            for (j = y1; j <= y2; ++j){
                if (c[i][j] != 0){
                    p = i;
                    q = j;
                }
            }
        if (p == x1 &&q == y1)
            lt(x1, y1, x2, y2);
        if (p == x1 && q == y2)
            lb(x1, y1,x2, y2);
        if (p == x2 && q == y1)
            rt(x1, y1,x2, y2);
        if (p == x2 && q == y2)
            rb(x1, y1,x2, y2);
    }
    else
    {
        for (i = x1; i <= x2; ++i)
            for (j = y1; j <= y2; ++j){
                if (c[i][j] != 0){
                    p = i;
                    q = j;
                }
            }
        if (p <= (x1 + (x2 - x1) / 2))//注意范围
            {if (q <= (y1 + (y2 - y1) / 2))
                lt(x1, y1, x2, y2);//左上
            else
                lb(x1, y1, x2, y2);}//左下
        if (p > (x1 + (x2 - x1) / 2))
            {if (q <= (y1 + (y2 - y1) / 2))
                rt(x1, y1, x2, y2);//右上
            else
                rb(x1, y1, x2, y2);}//右下
        cover(x1, y1, (x1 + (x2 - x1) / 2), (y1 + (y2 - y1)/2));//平分成四块后调用递归
        cover((x1 + (x2 - x1) / 2 + 1), y1, x2, (y1 + (y2 - y1) / 2));
        cover(x1, (y1 + (y2 - y1) / 2 + 1), (x1 + (x2 - x1) / 2), y2);
        cover((x1 + (x2 - x1) / 2 + 1), (y1 + (y2 - y1) / 2 + 1), x2, y2);
    }
}

void out()//输出
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << c[j][i] << ' ';
        }
        cout << endl;
    }   
}

int main()
{
    int n, x, y;
    cin >> n >> y >> x;
    for (int i = 1; i <= n; i++)
    {
        k = k * 2;
    }
    c[x][y] = 7;
    cover(1, 1, k, k);
    out();
    return 0;
}
```

[数据结构——残缺棋盘覆盖](https://blog.csdn.net/weixin_43360801/article/details/104169366)