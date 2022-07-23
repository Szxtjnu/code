#include<stdio.h>
void arraychange(int a[][3])
{
	int temp; 
	for(int i=0;i<3;i++)
		for(int j=i+1;j<3;j++)
			{temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;}
}
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	arraychange(a);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{printf("%3d",a[i][j]);
		if(j==2)printf("\n");
		}
		
	return 0;
}
