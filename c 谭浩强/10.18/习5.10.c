#include<stdio.h>
int main()
{
	int i,n=20;
	double sum=0,a=2,b=1,temp;
	for(i=1;i<=20;i++)
	{
		sum=sum+a/b;
		temp=a;
		a=temp+b;
		b=temp;
	}
	printf("The Answer is %.6f",sum);
	return 0;
 } 
