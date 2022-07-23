#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int x=0;
	x=a[0][0]+a[1][1]+a[2][2];
	printf("%3d",x);
	return 0;
 } 
