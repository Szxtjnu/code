/*problem: a + b 
  Input a b <= 10^500*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
  char a1[100], b1[100];
  int a[100], b[100], c[100], lena, lenb, lenc;
  int i, x;
  memset(a, 0, sizeof(a)); //初始化数组
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  gets(a1);//读入数组
  gets(b1);
  lena = strlen(a1);//求数组长度
  lenb = strlen(b1);
  for ( i = 0; i < lena; ++i)//数组逆置
  {
    a[lena - i] = a1[i] - '0';
  }
  for ( i = 0; i < lenb; ++i)
  {
    b[lenb - i] = b1[i] - '0';
  }
  lenc = 1;
  x = 0;
  while (lenc <= lena || lenc <= lenb)  //计算的长度等于最长的加数的位数
  {
    c[lenc] = a[lenc] + b[lenc] + x; 
    x = c[lenc] / 10;  //进位
    c[lenc] %= 10;  //进位之后剩下的个位数字，或者是没有进位的个位数字
    lenc++;
  }
  c[lenc] = x;  //如果最高项求和之后有进位的话，用来记录
  if (c[lenc] == 0)//消除前导0
  {
    lenc--;
  }
  for (  i = lenc; i > 0; --i)  //逆序输出
  {
    cout << c[i];
  }
  cout << endl;
  return 0;
}