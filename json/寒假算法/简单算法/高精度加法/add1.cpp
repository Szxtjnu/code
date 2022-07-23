//高精度加法优化
#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 100001
using namespace std;

int add(int x[], int y[], int z[], int len)  //用来做加法的函数
{
    int i, j;
    for ( j = 0; j < len; ++j) //从下标为0开始逐次加到len-1
    {
        z[j] += x[j] + y[j];  //相加
        for ( i = j; i < len; ++i) //判断是否有进位出现
        {
            if (z[i] >= 10) //如果有进位
            {
                z[i + 1] += z[i] / 10; //最高位的上一位需要加1.这里改成 ++ z[i+1]效率更高，因为进位在加法里只能进1
                z[i] -= 10; //这里也可以写成z[i] %= 10；但是效率略慢
                if (z[len] > 0) //如果最高位进位了，需要将最大位数+1
                {
                    len++;
                }
                if (z[i + 1] < 10)
                {
                    break;
                }   
            }   
        }
    }
    return len;
}

void init(int x[], string str, int len) //输入字符串并且逆序排放
{
    for (int i = 0; i < len; ++i)
    {
        x[len - i - 1] = str[i] - '0';
    }
}

void output(int z[], int len) //字符串的输出
{
    for (int i = len - 1 ; i >= 0; --i)
    {
        cout << z[i];
    }
    cout << "\n";
}

int main()
{
    string str1, str2;
    int a[MAXN] = {0}, b[MAXN] = {0}, z[MAXN] = {0};//初始化
    int lena, lenb, len;
    cin >> str1 >> str2;
    lena = str1.size();
    lenb = str2.size();
    init(a, str1, lena);
    init(b, str2, lenb);
    if (lena >= lenb)
    {
        len = add(a, b, z, lena);
    }
    else
    {
        len = add(b, a, z, lenb);
    }
    output(z, len);
    return 0;
}