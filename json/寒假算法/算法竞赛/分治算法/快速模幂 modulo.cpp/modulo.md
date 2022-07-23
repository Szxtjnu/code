寒假算法记录 
---

---

![](https://img.imgdb.cn/item/601a8d313ffa7d37b3fa6684.jpg)

---
### 快速模幂 modulo.cpp 
#### 题目描述：
> 试求a^b%n的值，其中a，b，n均为整数范围内的数。
#### 输入格式：
> 三个整数即a，b，n。
#### 输出格式：
> 输出结果。
#### 输入样例：
> 1 1 1
#### 输出样例：
> 0
---
#### _题目分析_：
&#8195;快速模幂是一道很神奇的题目，按常理来说，如果想求一个数n的模，那么就要算n%x，放到这里来说就是先算a^b，再模。如果用一般的幂算法的话，O(N)显然太大了，但是用快速幂的话，就很快的解决了，但是这里有一个问题，就是快速幂算的时候说的是结果在整型内，大不了我们可以unsigned，肯定是溢出不了的。

&#8195;但是重点来了，**这里的数据是底数base，指数power都有可能到int**，即使是$2^{100}$,结果也是会溢出的，所以，这里不能用朴素算法。

&#8195;那应该怎么办呢？这里我们需要用到蒙哥马利算法。这里我们推导一下。
$$ (ab)modc=[(a mod c)*(bmodc)]modc$$
$$amodc=d\Rightarrow a=tc+d$$
$$bmodc=e\Rightarrow b=kc+e$$
$$abmodc=(tc+d)(kc+e)modc$$
$$=(tkc^2+(te+dk)c+de)modc$$
$$=demodc=[(a mod c)*(bmodc)]modc$$
当b=1时候,就能推出我们要用的公式了.这样，我们就可直接用这个结论了，分析一下，我们每次先判断power是否是奇数,如果是奇数的话,我们先要摘出来那个多出来的数,让多出来的那个数先对n取余,并把它记录下来.剩余的偶数幂部分我们让他迭代.
根据公式$(a^2)^{\frac{b}{2}}modc$ 就等于$(a^2modc)^{\frac{b}{2}}modc$.

---

**代码:**
``` cpp
#include<iostream>
#include<cstdio>
using namespace std;
//朴素算法
// int main()
// {
//     int base, power, k;
//     int result = 1;
//     cin >> base >> power >> k;
//     for (int  i = 1; i <= power; ++i)
//     {
//         result = result * base;
//         result = result % k;
//     }
//     result = result % k;
//     cout << result << endl;
//     return 0;
// }

//快速算法
int main()
{
    long long base, power;
    int k;
    int result = 1;
    cin >> base >> power >> k;
    base = base % k;//如果base大于k的话,这样算一下可以减少后面的复杂度
    if (power == 0)
    {
        result = 1;
    }
    
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * base) % k;
        }
        power /= 2;
        base = (base * base) % k;
    }
    cout << result << endl;
    return 0;
}
```