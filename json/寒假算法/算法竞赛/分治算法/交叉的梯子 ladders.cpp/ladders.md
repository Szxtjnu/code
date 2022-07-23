### 寒假算法记录

---





---

### 交叉的梯子 ladders.cpp

#### 题目描述：

> 如图所示，有一个狭窄街道上竖立着两栋楼，右楼有一个长为x的梯子搭在左楼，左楼有一个长为y的梯子搭在右楼，两体字的交叉点的高度在c处。问这个街道的宽度？
>
> ![](http://poj.org/images/2507_1.jpg)

#### 输入格式：

> 每行一组数据,表示x,y,c

#### 输出格式：

>输出街道的宽度。

#### 输入样例：

>30	40	10
>
>12.619429	8.163332	3
>
>10	10	3
>
>10	10	1

#### 输出样例：

> 26.033
>
> 7.000
>
> 8.000
>
> 9.798




---



#### _题目分析_：

​	这道题是一道典型的几何问题，设街道的宽度为L，我们要找到的就是街道宽度L和我们输入的x,y,c这三个值之间的关系。作图如下：

![](https://img.imgdb.cn/item/600e7eb93ffa7d37b3f2a9ae.png)

​	根据相似，我们可以得到
$$
\frac{c}{DC}=\frac{AB}{AC},\frac{c}{EA}=\frac{BC}{AC},又有\frac{AB}{AC}+\frac{BC}{AC}=1
$$
$$
所以就有\frac{c}{DC}+\frac{c}{EA}=1
$$

$$
即\frac{c}{\sqrt[]{(y^2-AC^2)}}+\frac{c}{\sqrt[]{(x^2-AC^2)}}=1
$$

$$
通分一下：c\times\sqrt[]{(y^2-AC^2)}+c\times\sqrt[]{(x^2-AC^2)}=\sqrt[]{(y^2-AC^2)}\times\sqrt[]{(x^2-AC^2)}
$$

​	这样，我们就得到了关系式，那么接下来就是运用二分法来求解L了。

​	需要注意的是：这里题目中给的精度是小数点后三位，那么我们二分的步长就是小数点后四位。二分的初始left为0，right为x和y中的最小值



---



**代码如下：**

``` c++
#include<cmath>
#include<iostream>
using namespace std;
double x, y, c;
bool check(double t)
{
    double a, b;
    a = sqrt(x * x - t * t);
    b = sqrt(y * y - t * t);
    if (a*c+b*c-a*b> 0)
        return true;
    else
        return false;
}
int main()
{  
    while(~scanf("%lf%lf%lf",&x,&y,&c))
    {
        double r, l, mid;
        l = 0;
        r = (x > y ? y : x);
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (check(mid))
                r = mid - 0.0001;
            else
                l = mid + 0.0001;
        }
        printf("%.3lf", r);
    }
    return 0;
}

```



参考资料：

[POJ2507](http://poj.org/problem?id=2507)