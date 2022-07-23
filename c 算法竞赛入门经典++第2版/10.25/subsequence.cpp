//subsequence.cpp
#include<stdio.h>
int main()
{
	float a,b,sum;
	scanf("%f%f",&a,&b);
	for(int i=a;i<=b;i++)
	{
		sum+=(1.0/i)/i;//这里如果写成1.0/(i*i)会导致数据的溢出 
	}
	printf("%.5f",sum);
	return 0;
}
