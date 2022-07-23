//3.1国民生产总值 
#include<stdio.h>
#include<math.h>//调用数学函数pow 
int main()
{
	float a,b,c;
	b=0.07;
	a=10;
	c=pow(1+b,a);
	printf("c=%f\n",c);
	return 0; 
}
