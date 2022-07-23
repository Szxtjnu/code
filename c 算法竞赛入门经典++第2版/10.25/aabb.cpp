//aabb.cpp
#include<stdio.h>
#include<math.h>
int main()
{
	for(int a=1;a<10;a++)
		for(int b=0;b<10;b++)
		{
			int n=1100*a+11*b;
			int m=floor(sqrt(n)+0.5);
			if(m*m==n)	printf("%d\n",n);
		}
	return 0;
 } 

