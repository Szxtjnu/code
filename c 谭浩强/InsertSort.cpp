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
	printf("������Ҫ�������ֵĸ�����\n");
	scanf("%d",&f);
	int a[f];
	printf("������Ҫ��������֣�\n");
	for(int i=0;i<f;i++)
	{
		scanf("%d",&a[i]);
	}
	
	InsertSort(a,f);
	
	printf("�����Ľ���ǣ�\n");
	for(int i=0;i<f;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
