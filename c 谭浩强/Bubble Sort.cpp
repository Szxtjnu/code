#include<stdio.h>
void BubbleSort(int k[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{	
		bool flag=true;
		for(j=0;j<n-1-i;j++)
		{
			if(k[j]>k[j+1])
			{
				temp=k[j+1];
				k[j+1]=k[j];
				k[j]=temp;
				flag=false;
			}	
		}
		if(flag)
		break;
	} 
}
int main()
{
	int f;
	printf("请输入要排序数字的个数：\n");
	scanf("%d",&f);
	int a[f];
	printf("请输入要排序的数字：\n");
	for(int i=0;i<f;i++)
	{
		scanf("%d",&a[i]);
	}
	
	BubbleSort(a,f);
	
	printf("排序后的结果是：\n");
	for(int i=0;i<f;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
 
