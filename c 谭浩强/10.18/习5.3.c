#include<stdio.h>
int GCD(int a,int b)
{
	int temp=0,r=1;

	while(r!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int LCM(int a,int b) 
{
	int temp_lcm;
	temp_lcm=a*b/GCD(a,b);
	return temp_lcm;
}
int main()
{
	int m,n;
	int gcd_temp,lcm_temp;
	scanf("%d,%d,",&m,&n);
	gcd_temp=GCD(m,n);
	lcm_temp=LCM(m,n);
	printf("���Լ��Ϊ%d,��С������Ϊ%d",gcd_temp,lcm_temp);
	return 0;
 } 
