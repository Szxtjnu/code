#include<stdio.h>
int main()
{
	double high=50,sum=100;
	int i,count;
	for(i=2;i<=10;i++)
	{
		sum=sum+high*2;
		high=high/2;
	}
	printf("第十次落地时共经过%f米\n",sum);
	printf("第十次反弹%f米\n",high);
	return 0;
}
