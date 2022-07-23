//Transpose 2D Array.cpp

#include<stdio.h>
#define N 3
int array[N][N];
void transpose2darray(int array[][3])
{
	int temp;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			temp=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=temp;
		}
}
int main()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	scanf("%d",&array[i][j]);
	transpose2darray(array);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%5d",array[i][j]);
			printf("\n");
	}
	return 0;
}
