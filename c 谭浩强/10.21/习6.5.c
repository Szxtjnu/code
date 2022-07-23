#include<stdio.h>
int main()
{
	int N;
	printf("Enter :\n");
	scanf("%d",&N);
	int a[N],i,j,temp;
	printf("Enter array a:\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array a:\n");
	for(i=0;i<N;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
	if(N%2!=0)
	for(i=0,j=N-1;i<N/2,j>N/2;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	else
	{
		for(i=0,j=N-1;i<=N/2,j>=N/2;i++,j--)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
	}
	for(i=0;i<N;i++)
	{
		printf("%5d",a[i]);
	}
	return 0;
	
	
	
	
	
}
