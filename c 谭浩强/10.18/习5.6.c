#include<stdio.h>
int main()
{
	double temp=1,sum=0;
	int i;
	for(i=1;i<=20;i++)
	{
		temp=temp*i;
		sum=sum+temp;
	}
	printf("The answer is :%22.15e\n",sum);
	return 0;
}
