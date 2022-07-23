## 寒假算法记录 
---
![](https://img.imgdb.cn/item/600d5d813ffa7d37b3621318.jpg)
---
### 发疯的奶牛 cow.cpp POJ2456
#### 题目描述：
> 农夫John建造了一座很长的畜栏，它包括N(2<=N<=100000)个隔间，这些小隔间的位置为x₀,...,xN-1(0<=xi<=1000000000)均为整数，各不相同.
> John的C (2<=C<=N)头牛每头分到一个隔间。牛都希望互相离得远点。怎样才能使任意两头牛之间的最小距离尽可能的大，这个最大的最小距离是多少呢？
#### 输入格式：
> * Line 1: Two space-separated integers: N and C

> * Lines 2..N+1: Line i+1 contains an integer stall location, xi
#### 输出格式：
>* Line 1: One integer: the largest minimum distance
#### 输入样例：
> 5  3
> 
> 1
> 2 
> 8
> 4
> 9
#### 输出样例：
> 3
---
#### _题目分析_：
&#8195;首先读题，有*100_000*个隔间，但是有*1e9*这么多个位置。这里很关键，我第一次就把位置当作了隔间数，然后就想只要是算出max的相隔距离就好了。但是看了给的数据发现不对，让第一行输入的是奶牛数和隔间数。

&#8195;那么应该怎么想这个问题呢？就拿给的例子来说吧。3头奶牛，5个隔间，每个隔间的位置也给了。这道题先说好肯定是要用**二分**的。那么先求一个mid值，这个数值肯定是在第一个隔间的位置和第五个隔间的位置之间的。在例子里面就是 mid∈(1,9).

&#8195;所以，这里用数组来模拟第几个隔间，然后数组里面的数模拟第几个位置。第一头奶牛一定是放在第一个隔间，并且设一个tmp来记录第一个隔间，然后拿第二个隔间的位置-第一个隔间的位置，如果比取的mid大的话，那么就证明这个位置有隔间，也就能放一头牛，那么就让牛数++，然后把这个隔间的位置记录到tmp里面。这样不停的判断直到最后一个隔间。如果最后的牛数比输入的牛数多，那么就证明这个mid值成立。

&#8195;但是这里要的是**最大的最小值**，所以还要接着算下去，这里就涉及到while里面怎么写的问题了。通过分析给的数据，如果mid不行的话，如果r=mid-1，就可能导致提前退出while循环，得不到最大的最小值。如果mid成立的话，肯定是从mid下一项开始判断。

&#8195;这里还要探究一下输出结果的问题，这里输出的是l-1，因为当mid成立了以后，判断语句后面接着是一个+1，所以这里要+1.这里不用mid输出的原因是这里格式是lld。

---
#### 代码如下：
``` cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100005;
int n, c;
int a[MAXN];
bool check(int k) 
{
    int tmp = a[0], cownum = 1;
    for (int  i = 0; i < n; ++i)
    {
        if (a[i] - tmp >= k)
        {
            tmp = a[i];
            cownum++;
        }
    }
    if (cownum >= c)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long l = 0, r = 3e9;
    int mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if(check(mid))
            l = mid + 1;
        else
            r = mid ;
    }
    printf("%lld",l - 1);
    return 0;
}

```

[POJ2456](http://poj.org/problem?id=2456)