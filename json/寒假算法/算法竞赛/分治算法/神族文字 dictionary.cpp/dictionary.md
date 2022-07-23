## 寒假算法记录
---
![](https://img.imgdb.cn/item/600c12f13ffa7d37b3c9c0dc.jpg)
冰冰！
---
### 神族文字 POJ 2503
#### 题目描述：
> 本人某天突然发现了一本来自上古的魔法书，里面的文字用的是传说的“神族文字”，于是我便去万能的桃饱网上寻找这样的一本字典，巧了还真就被我找到了。
#### 输入格式：
> 输入的词典内容最多包括100000个词条，每个词条对应的是一个英文单词，英文单词和“神族文字”之间用空格隔开。词条输入完毕之后输入的是需要翻译的“神族文字”。注：每个词条仅出现一次。
#### 输出格式：
> 输出翻译好的英文，每行一个字。若查不到，输出“eh”
---
#### _题目分析_：
- ### 要点：
  - 怎样输入一个尤为重要，这里的输入分两种，一种是输入**词条**，有**两个词**要输入，而且中间是**空格**；还有一种是要翻译的词，只有一个。
  - 这里的数据量是*100000*这个量级的，所以用枚举的话会超时的，所以要采用二分来找，那么这就引出了下面的两个问题：
    - 众所周知，二分是对一个有序的列来找的，所以这里要用到sort排序。
    - 怎么写关于字符串的二分？
---
### 代码
``` cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 100010;
struct node
{
    char e[30], s[30];
}dic[MAXN]; //定义结构体，存储英文单词和特殊词

char t[30]; //temp存放需要查找的特殊词
int len;//词典的长度
bool cmp(const node a,const node b){ //针对sort函数写的排序方法
    return strcmp(a.s, b.s);
}
int search(char *s)//二分排序法
{
    int bot = 0, top = len - 1;
    while (bot <= top){
        int mid = bot + (top - bot) / 2;
        if(strcmp(dic[mid].s,s)==0)
            return mid;
        else if(strcmp(dic[mid].s,s)>0)
            top = mid - 1;
        else
            bot = mid + 1;
    }
    return -1;
}

int main()
{
    len = 0;
    char z;
    while(scanf("%s%c",dic[len].e,&z) != EOF){
        if (z == '\n'){         //判断是否输入的需要查找的词
            strcpy(t, dic[len].e);
            break;
        }
        scanf("%s", dic[len++].s);//先写入dic[len]，再len++
    }
    sort(dic, dic + len, cmp);//调用sort函数进行排序
    int num = search(t);//进行查找
    if (num >= 0)
        printf("%s\n", dic[num].e);
    else
        printf("eh\n");
    while (scanf("%s", t) != EOF){
        num = search(t);
        if (num >= 0)
            printf("%s\n", dic[num].e);
        else
            printf("eh\n");
    }
    return 0;
}

```
参考文献：

[sort函数对字符串的排序]:https://blog.csdn.net/sinat_31608641/article/details/107856427
[sort函数对字符串的排序];

[POJ 2503题解]:https://blog.csdn.net/weixin_33912246/article/details/94059429?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.control
[POJ 2503题解]；

[poj 2503]:http://poj.org/problem?id=2503
[poj 2503];