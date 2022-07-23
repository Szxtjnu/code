//daffodil.cpp
#include<stdio.h>
int main()
{
	int n,a,b,c;
	for(int i=100;i<1000;i++)
	{
		a=i/100;
		b=(i-a*100)/10;
		c=i%10;
		n=a*a*a+b*b*b+c*c*c;
		if(i==n)
		  printf("%3d  ",i);
	}
	return 0;
}
