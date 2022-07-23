//hanxin.cpp
#include<stdio.h>
int main ()
{
	int n,r3,r5,r7,flag=0;
	scanf("%d%d%d",&r3,&r5,&r7);
	for(int i=10;i<=100;i++)
	{
		if((i%3==r3)&&(i%5==r5)&&(i%7==r7))
		{
			printf("%d",i);
			flag=0;
			break;
			}
		else flag=1;
	}
	if(flag)
	printf("NO ANSWER!");
	return 0;
 } 
