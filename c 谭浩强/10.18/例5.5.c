#include<stdio.h>
int main()
{
	int i;
	for(i=100;i<=200;i++)
	{
		if(i%3==0)
		{
			continue;
		}
		else
		printf("%d  ",i);
	}
	printf("\n");
	return 0;
}
