//2darray.cpp

#include<stdio.h>
int max(int a[][4])
{
	int max=a[0][0];
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			if(max<a[i][j])
				max=a[i][j];
	return(max);
}
int main()
{
	int a[3][4]={{1,3,5,7},{2,4,6,8},{15,17,34,12}},temp;
	temp=max(a);
	printf("%d",temp);
	return 0;
}
