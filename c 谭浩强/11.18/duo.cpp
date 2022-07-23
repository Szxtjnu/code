#include<stdio.h>
float duo(int n,int x)
{
	if(n==0) return(1);
	else if(n==1) return(x);
	else
	return ((2*n-1)*x-duo((n-1),x)-(n-1)*duo((n-2),x))/n;
}
int main()
{
	int x,n;
	float temp;
	scanf("%d%d",&n,&x);
	temp=duo(n,x);
	printf("%.2f",temp);
	return 0;
}
