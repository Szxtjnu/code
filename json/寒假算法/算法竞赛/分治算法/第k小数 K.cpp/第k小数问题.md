## 寒假算法记录 


---

---

###  第k小数V1

#### 题目描述：

> 对于给定的n个元素的无序数组，要求从中找出第k小的元素
#### 输入格式：
> 第一行是总数n(1<n<100000)和k，第二行是n个待比较元素
#### 输出格式：

>第k小的数在数组中的位置
#### 输入样例：

>5 3
>25	9	90	57	3
#### 输出样例：

>   1


---

#### _题目分析_：

​	这道题理解起来很容易，就是问一个数列中第k小的数。如果我们用排序的话很轻松就能写出来，但是我们这里尝试一下不用排序的方法来写。

​	那么，不用排序怎么写呢？分析一下，要想知道第k小的数字，那么就需要知道第k小的数之前的所有数的排序方式。也就是说，需要将这个数列处理成第k个数前的数字全比他小，之后的数字全比他大，那么不需要将这些数字全部排好再去找这个第k小的数。

​	这就是这个代码的大体思路。

​	用代码实现的话就是：我们首先先假定第一个数是第k小的数字，并且假设这个数字左侧都是比他小的，右侧都是比他大的，那么用i记录这个数的位置，j记录要比较数的位置。首先从整个数列的最右端开始找，找到一个比第一个数小的数字，然后将这两个数字交换，并交换i,j的值。之后让基准数与被比较数比较，找出比基准数大的数交换位置。直到i,j相等。这样换可以保证我们选的这个基准数的左面全都是比它小的，右面全都是比他大的。这样，我们就得到了基准数在整个数列里的位置，我们拿输入的k值与i值相比，用二分的思想，直到找到我们要找的那个数。

---

### 代码实例：

``` cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100005;
int a[MAXN], b[MAXN];
int k, i, j, n;

int main()
{
    void move(int, int);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    move(1, n);
    return 0;
}

void Swap()
{
    swap(a[i], a[j]);
    swap(i, j);
}
void move(int start, int end)
{
    i = start;
    j = end;
    while (i != j)
    {
        if (i < j){
            if (a[i] > a[j])
                Swap();
            else
                --j;
        }
        if (i > j)
        {
            if (a[i] < a[j])
                Swap();
            else
                ++j;
        }
    }
    if (i < k)
        move(i + 1, end);
    else if (i > k)
        move(start, i - 1);
    else{
        for (int l = 1; l <= n; ++l){
            if (b[l] == a[i])
            {
                cout << l << endl;
                break;
            }
        }
    }
}
```

---

## 第k小数V2

####  题目描述：

>   ​	对于两个有序数组a[n]和b[m] (1<n,m<100000)，找出第k小的数。

#### 输入格式：

>   ​	第一行三个整数n、m、k；
>
>   ​	第二行是第一个有序数组的n个元素；
>
>   ​	第三行是第二个有序数组的m个元素

#### 输出格式:

>   ​	第k小的数

#### 输入样例：

>   6	7	6
>
>   786	3891	4258	4694	7130	7899
>
>   357	720	1292	2579	7889	9255	9611

#### 输出样例：

>   3891

---

#### 代码：

```c++
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1000010;
int a[MAXN], b[MAXN];

int main()
{
    int search(int, int, int, int, int);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int  i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    printf("%d", search(0, n - 1, 0, m - 1, k));
    return 0;
}
 
int search(int s1, int e1, int s2, int e2, int kth)
{
    int idxA = (s1 + e1) / 2;
    int idxB = (s2 + e2) / 2;
    int lenA = idxA - s1 + 1;
    int lenB = idxB - s2 + 1;
    if (s1 > e1){
        lenA = 0;
    }
    if (s2 > e2){
        lenB = 0;
    }
    int len = lenA + lenB;
    if (len > kth){
        if (0 != lenB && (0 == lenA || a[idxA] <= b[idxB])){
            return search(s1 , e1, s2, idxB - 1, kth);
        }
        else
            return search(s1, idxA - 1, s2, e2, kth);
    }
    else{
        if (kth == len){
            if (lenA == 0){
                return b[idxB];
            }
            else if (lenB == 0){
                return a[idxA];
            }
        }
        if (0 != lenA && (0 == lenB || a[idxA] <= b[idxB]))
            return search(idxA + 1, e1, s2, e2, kth - lenA);
        else
            return search(s1, e1, idxB + 1, e2, kth - lenB);
    }
}
```

---

### 第k小数V3

#### 题目描述：

>   ​	给出两个长度分别为M和N的数组a，b，从两个数组中各任选一个相加，将和放入一个新数组c，现在问新数组从小到大排序后第K个数是多大。 m，n， k(1<=m,n<=100000， 1<= k <= n *m)  数组元素整型范围

#### 输入格式：

>   ​	输入可能包含多个测试案例。
>   ​	对于每个测试案例，输入的第一行为三个整数m，n， k(1<=m,n<=100000， 1<= k <= n *m)：n，m代表将要输入数组A和B的长度。
>   ​	紧接着两行， 分别有m和n个数， 代表数组A和B中的元素。数组元素范围为[0,1e⁹]。

#### 输出格式：

>   ​	对应每个测试案例，
>
>   ​	输出由A和B中元素两两相加得到的数组c中第K小的数字。

#### 输入样例：

>   2	2	3
>
>   1	2
>
>   3	4
>
>   3	3	4
>
>   1	 2	7
>
>   3	4	5

#### 输出样例：

>   5
>
>   6

---

### 题目分析：

​	两组数据，均排好序，问这两组数据两两求和之后，第k小的数是多少。那么我们先想想，把和都求出来，但一看数据，如果两个数组的数字个数都取最大值的话，那么就是100000×100000这么多个和数，那么我们知道最简单的数组排序时间复杂度是nlogn，这样算下来肯定要超时。那么应该怎么做呢？

​	这样线性的数据已经给我们了，我们就要好好利用一下。那么线性数据用二分法来做是最方便的。那么我们应该怎么用二分呢？二分的核心思想是拿着一个基准数来和我们计算的数比较，来不断的进行修正，来把计算值不断的逼近基准数，从而实现求解。那么这个基准数显然就是k了，那么我们需要算的就是一个第p个数，看这第p个数是大于k，等于k，还是小于k，从而不断的调整我们输入的数字来使k=p。

​	那么这里的第p个数的大小应该是多少呢？作为二分算法，我们很容易就想到了mid值。这个mid值也好算，就是两个数组头之和加两个数组尾之和除以2就得到了。那么我们应该怎么确定这个mid在第几位上呢？也就是p到底是多少。

​	第p个数的另外一个说法就是这个数前面有n个比他小的数，那么这个数就是第n+1位。我们只需要求有几个比mid小的数，也就知道了p的值了。

​	接下来就是递归，直到k==p。

---

#### 代码示例：

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN = 100010;
long long a[MAXN], b[MAXN];

int compare(const void *p, const void *q)
{
    return *(long long *)p - *(long long *)q;
}
long long cal(long long a[], long long m, long long b[], long long n, long long mid)
{
    long long i,j;
    long long cnt = 0;
    j = n - 1;
    for (i = 0; i < m ; ++i){
        while (j >= 0 && a[i] + b[j] > mid)
        {
            --j;
        }
        cnt += (j + 1);
    }
    return cnt;
}

long long findk(long long a[], long long m, long long b[], long long n, long long k)
{
    long long min = a[0] + b[0];
    long long max = a[m - 1] + b[n - 1];
    long long mid;

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (k <= cal(a, m, b, n, mid)){
            max = mid - 1;
        }
        else{
            min = mid + 1;
        }
    }
    return min;
}

int main(int argc, char const *argv[])
{
    long long m, n, k, i;
    while (scanf("%lld%lld%lld", &m, &n, &k) != EOF)
    {
        for (i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        printf("%lld\n", findk(a, m, b, n, k));
    }
    return 0;
}

```

