#include<stdio.h>
int main()
{
	int num,a,b,c;
	printf("请输入要判断的三位数：\n");
	scanf("%d",&num);
	a=num/100;
	b=num/10-a*10;
	c=num%10;
	if(num==a*a*a+b*b*b+c*c*c)
	printf("YES");
	return 0;
 } 
