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
	printf("������Ҫ�������ֵĸ�����\n");
	scanf("%d",&f);
	int a[f];
	printf("������Ҫ��������֣�\n");
	for(int i=0;i<f;i++)
	{
		scanf("%d",&a[i]);
	}
	
	BubbleSort(a,f);
	
	printf("�����Ľ���ǣ�\n");
	for(int i=0;i<f;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}
 
