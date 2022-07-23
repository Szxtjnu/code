#include<stdio.h>
int main()
{
	int i,j,temp,min,count=0;
	int a[10]={2,3,5,6,9,8,7,4,1,0};
	for(i=0;i<9;i++)
	{
		min=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
			if(min!=i)  //如果该次遍历中i为最小，便可以不用进行交换，减少运算量 
			{
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		}	
	}
	for(i=0;i<10;i++)
	printf("%3d",a[i]);
	return 0;
}
