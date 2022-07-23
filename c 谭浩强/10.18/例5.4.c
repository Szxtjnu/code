#include<stdio.h>
#define SUM 100000
int main()
{
	float count,total,aver;
	int i;
	for(i=1,total=0;i<=1000;i++)
	{
		printf("please enter amount:");
		scanf("%f",&count);
		total=total+count;
		if(total>=SUM)
		break;
	}
	aver=total/i;
	printf("The number is = %d\n",i);
	printf("The average is = %10.2f",aver);
	return 0;
 } 
