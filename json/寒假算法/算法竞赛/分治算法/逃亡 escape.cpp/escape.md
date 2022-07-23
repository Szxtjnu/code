## 寒假算法记录 ##

---
![th](https://mmbiz.qpic.cn/mmbiz_jpg/HhoEMZZMsiaTMHJrvKCdVG4GSKibuqKfyoQMMqpbQXo2RCVuW3dUdxQSvQRWUW7oYN1iaIprrWEkeNpQ28jma1Wog/640)
---

### 逃亡 escape.cpp
#### 题目描述：
> 邪狼紧张地说：“老大，警察快追过来了，我们快逃跑吧！”
> 
> 修罗王傲然道：“在我的字典里没有逃跑。。。”
> 
> 邪狼内心崇敬地想：“老大实在是太有领袖范了……”
> 
> 修罗王接着说：“只有战略转移。”
> 
> 邪狼：“……”
> 
> 现在，修罗王和邪狼两人需要从A地出发尽快到达B地。出发时A地有一辆可带一人的自动驾驶悬浮车。又知两人步行速度相同。问怎样利用小车才能使两人尽快同时到达B地。
#### 输入格式：
> 有三个int类型整数，分别表示A、B两地的距离，步行速度和车速。
#### 输出格式：
> 有一个小数位数为2的浮点数，即最短时间。
#### 输入样例：
> 100 5 10
#### 输出样例：
> 14.00

---
#### _题目分析_：
![](https://img.imgdb.cn/item/6006ef393ffa7d37b3fedaf5.jpg)

---

#### 代码：
``` cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    float s, v1, v2, t1, t2, t3, t4, c1, c2, c;
    cin >> s >> v1 >> v2;
    c1 = 0, c2 = s;
    do
    {
        c = (c1 + c2) / 2;
        t3 = c / v2;
        t1 = t3 + (s - c) / v1;
        t4 = (c - t3 * v1) / (v1 + v2);
        t2 = t3 + t4 + (s - (t3 + t4) * v1) / v2;
        if (t1 < t2){
            c2 = c;
        }   
        else{
            c1 = c;
        }
    } while (fabs(t1-t2)>1e-4);
    printf("%4.2f", t1);
    return 0;
}
```
----