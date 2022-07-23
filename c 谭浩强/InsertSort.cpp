#include<stdio.h>
void InsertSort(int k[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=k[i];
		j=i-1;
		while(j>-1&&temp<k[j])
		{
			k[j+1]=k[j];
			j--;
		}
		k[j+1]=temp;
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
	
	InsertSort(a,f);
	
	printf("排序后的结果是：\n");
	for(int i=0;i<f;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
