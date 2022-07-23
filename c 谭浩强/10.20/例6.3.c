#include<stdio.h>
int main()
{
	int a[10],i,j,temp;
	int flag=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++)
	{
		flag=0;
		for(j=0;j<9-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			flag=1;
		}
		if(flag=1)
		break;
	}
	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
