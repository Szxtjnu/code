//SelectSort.c
#include<stdio.h>
void SelectSort(int k[],int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(k[j]<k[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=k[min];
			k[min]=k[i];
			k[i]=temp;
		}
	}
}
int main()
{
	int f;
	printf("������Ҫ�������ֵĸ�����\n");
	scanf("%d",&f);
	int a[f];
	printf("������Ҫ��������֣�\n");
	for(int i=0;i<f;i++)
	{
		scanf("%d",&a[i]);
	}
	
	SelectSort(a,f);
	
	printf("�����Ľ���ǣ�\n");
	for(int i=0;i<f;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}

