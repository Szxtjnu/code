#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,x1,x2,derta,realpart,imagpart;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	if(fabs(a)<=0)
	{
		printf("该方程不为一元二次方程.\n");
	}
	else
	{
		derta=b*b-4*a*c;
		if(fabs(derta)<=1e-6)
		{	
			printf("有两个相等的根:%8.4f\n",-b/(2*a));
		}
		else 
			if(fabs(derta)>1e-6)
			{
				x1=(-b+sqrt(derta))/2*a;
				x2=(-b-sqrt(derta))/2*a;
				printf("该方程有不相等的两个实数根，分别为：%8.4f,%8.4f",x1,x2);
			}
			else 
			{
				realpart=-b/(2*a);
				imagpart=sqrt(-derta)/(2*a);
				printf("该方程无实根，两共轭复数分别为:%8.4f+%8.4fi",realpart,imagpart);
				printf("%.4f-%.4fi\n",realpart,imagpart);
			}
	}
	return 0;
 } 
