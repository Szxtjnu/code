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
	printf("��ʮ�����ʱ������%f��\n",sum);
	printf("��ʮ�η���%f��\n",high);
	return 0;
}
