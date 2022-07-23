//fac.cpp

#include<stdio.h>
int fac(int n)
{
	int temp;
	if(n<0)
	printf("n<0,Data Error!\n");
	else if(n==1||n==0)
	temp=1;
	else
	temp=fac(n-1)*n;
	return(temp);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fac(n));
	return 0; 
}
