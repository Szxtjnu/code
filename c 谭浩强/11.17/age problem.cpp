//age problem.cpp

#include<stdio.h>
int age(int n)
{
	int temp;
	if(n==1)
	temp=10;
	else
	temp=age(n-1)+2;
	return(temp);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",age(n));
	return 0;
}
