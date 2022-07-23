//which is the max.cpp 

#include<stdio.h>
int max(int x,int y)
{
	return(x>y?x:y);
}
int main()
{
	int a[10],m,n,i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(i=1,m=a[0],n=0;i<10;i++)
	{
		if(max(m,a[i])>m)
		{
			m=max(m,a[i]);
			n=i;
		}
	}
	printf("The largest number is %d\nIt is the %dth number.\n",m,n+1);
	
}
