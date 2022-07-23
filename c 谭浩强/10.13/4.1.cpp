#include<stdio.h>
int main()
{
	int a,b,c,max,temp;
	printf("请输入三个整数，并用逗号隔开：\n");
	scanf("%d,%d,%d",&a,&b,&c);
	temp=(a>b)?a:b;
	max=(temp>c)?temp:c;
	printf("三个整数之中的最大值为：%d\n",max);
	return 0; 
	
 } 
