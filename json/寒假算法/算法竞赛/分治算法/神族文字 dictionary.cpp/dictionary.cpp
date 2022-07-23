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
