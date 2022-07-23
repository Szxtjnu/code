//selectsort
#include<stdio.h>
int main()
{
	int a[10]={3,2,1,6,5,4,9,8,7,0};
	int i,j,temp,min;
	for(i=0;i<9;i++)
	{
		min=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[min])
			min=j;
			if(min!=i)
			{
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	printf("%d",a[i]);
	return 0;
 } 
