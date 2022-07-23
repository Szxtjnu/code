#include<stdio.h>
int main()
{
	int a[11]={0,1,2,3,5,6,7,8,9,10};
	int i,j,num,end,temp1,temp2;
	scanf("%d",&num);
	end=a[9];
	if(num>end)
	a[10]=num;
	else
	{
		for(i=0;i<10;i++)
	{
		if(num<a[i])
		{
			temp1=a[i];
			a[i]=num;
			for(j=9;j>i;j--)
			{
				a[j+1]=a[j];
			}
			a[i+1]=temp1;
			break;
		}		
	}
	}
	for(i=0;i<11;i++)
	printf("%5d",a[i]);
	return 0;
}
