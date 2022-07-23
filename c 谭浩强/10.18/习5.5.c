#include<stdio.h>
int main()
{
	int a,n,sum=0,i=1,temp=0;
	scanf("%d,%d",&a,&n);
	while(i<=n)
	{
		temp=temp+a;
		sum=sum+temp;
		a=a*10;
		++i;
	}
	printf("%d",sum);
	return 0;
	
}
