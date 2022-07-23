//selectsort.cpp

#include<stdio.h>
void selectsort(int a[],int n)
{
	int temp,flag,min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
			}
				temp=a[min];
				a[min]=a[i];
				a[i]=temp;
		
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	selectsort(a,n);
	for(int i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}
