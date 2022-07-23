#include<stdio.h>
#define N 4 
#define M 5 
void SaddlePoint(int a[4][5])
{
	int i,j,k,flag,max,min,col;
	for(i=0;i<N;i++)
	{
		max=a[i][0];
		col=0;
		for(j=0;j<M;j++)
		
			if(a[i][j]>max)
			{
				max=a[i][j];
				col=j;
				}
		flag=1;
		for(k=0;k<N;k++)
			if(max>a[k][col])
			{
				flag=0;
				continue;
				}
		if(flag)
			{
				printf("a[%d][%d]=%d\n",i,col,max);
				break;
				}
			
		}
	if(!flag)
	printf("It is no exist!\n");
	}
int main()
{
	int a[N][M],i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		scanf("%d",&a[i][j]);
	}
	SaddlePoint(a);
	return 0;
}
