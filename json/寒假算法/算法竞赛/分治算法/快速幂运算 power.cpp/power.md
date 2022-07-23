寒假算法记录 
---

---

![](https://img.imgdb.cn/item/6017fe243ffa7d37b3facdc8.jpg)

---
### 快速幂运算 power.cpp
#### 题目描述：
> 邪狼：“老大，好像还是不够油钱啊？”
> 
> 修罗王：“看来只好用我的独门绝技----能力增持术了。”
> 
> 邪狼：“听说能量增持数很霸道的？”
> 
> 修罗王：“没错，假设初始燃油能提供的能量为X，当我对它进行能量增持n秒后，该然后的能量将达到Xn”
> 
> 邪狼：“这么强大的技能啊，简直逆天了，不过怎么之前不见老大用过？”
> 
> 修罗王：“偶尔偷偷用几次没关系，经常用，燃油公司会找我麻烦的。”
> 
> 现已知X和n，试计算Xn的值。
#### 输入格式：
> 两个正整数，即X和n，其中X≥0，n≥0
#### 输出格式：
> 一个整数，即结果，保证结果不超过整型范围.
#### 输入样例：
> 3 2
#### 输出样例：
> 9
---
#### _题目分析_：
&#8195;我们通常算一个数的幂的时候，都是用一个for循环*x\*=x*来不断自乘。但是当n较大的时候，运算的时间会大大加长。普通的算法时间复杂度是O(N)

&#8195;我们计算2⁹时，先算出2*2=4的值，这样2⁹就可以写成4\*4\*4\*4\*2，再计算4\*4=16的值，则又可以写成16\*16\*2，这样就可以很快速的算出结果。

**代码如下：**
``` cpp
#include<iostream>
#include<cmath>
using namespace std;
int pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
    {
        int c = pow(a, b / 2);
        if ((b % 2) == 0)
        {
            return c * c;
        }
        else
            return c * c * a;
    }
}
int main()
{
    int X, n;
    cin >> X >> n;
    cout << pow(X, n) << endl;
    return 0;
}
```
----
&#8195;如何进一步的优化呢？这里就要提到c语言里面的位运算了。当我们在判断n是偶数还是奇数的时候，可以采用按位与运算符来判断，即n&1的值是否是0即可。n=n/2，也可以采用位运算来，就是把n的二进制位向右移动一位即可。

**代码如下：**
``` cpp
#include<iostream>
#include<cmath>
using namespace std;
long long pow(long long x, long long n)
{
    long long result = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        while ((n & 1) == 0) //如果n是偶数
        {
            n >>= 1;
            x *= x;
        }
    }
    result = x;
    while (n != 0)
    {
        n >>= 1;
        x *= x;
        if ((n & 1) != 0)
        {
            result *= x;
        }
    }
    return result;
}
int main()
{
    long long x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    return 0;
}
```

引用：

[位运算](https://baike.baidu.com/item/%E4%BD%8D%E8%BF%90%E7%AE%97/6888804?fr=aladdin)