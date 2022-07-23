#include<stdio.h>
void print(int a[][15],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(j==n-1)
				printf("%d",a[i][j]);
			else
				printf("%-4d",a[i][j]);
			printf("\n");
	}
}
void MagicSquareArray(int n)
{
	int num,row,col;
	int a[15][15];
	for(row=0;row<n;row++)
		for(col=0;col<n;col++)
		{
			a[row][col]=0;
		}
	num=1;row=0;col=n/2;
	a[row][col]=num;
	while(num<=n*n)
	{
		num++;
		if(row==0&&col==n-1)
			row++;
		else
		{
			row--;col++;
			if(row<0) row=n-1;
			if(col>n) col=0;
			if(a[row][col]!=0)
			{
				col--;
				row=row+2;
			}
		}
		a[row][col]=num;
	}
	print(a,n);
}
int main()
{
	int n;
	printf("Input n:\n");
	scanf("%d",&n);
	MagicSquareArray(n);
	return 0;
}
