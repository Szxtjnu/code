#include<stdio.h>
//递归求斐波那契数列 
int Fibonacci(int n)
{
	if(n<=2)
	return 1;
	else
	return Fibonacci(n-1)+Fibonacci(n-2);
}
int main()
{
	int i,n,ret=0;

	for(i=1;i<=40;i++)
	{
		ret=Fibonacci(i);
		printf("%12d",ret);
		if(i%4==0)
		printf("\n");
	}
	
	return 0;
}
