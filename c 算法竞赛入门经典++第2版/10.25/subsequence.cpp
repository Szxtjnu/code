//subsequence.cpp
#include<stdio.h>
int main()
{
	float a,b,sum;
	scanf("%f%f",&a,&b);
	for(int i=a;i<=b;i++)
	{
		sum+=(1.0/i)/i;//�������д��1.0/(i*i)�ᵼ�����ݵ���� 
	}
	printf("%.5f",sum);
	return 0;
}
