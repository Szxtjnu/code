#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,x1,x2,derta,realpart,imagpart;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	if(fabs(a)<=0)
	{
		printf("�÷��̲�ΪһԪ���η���.\n");
	}
	else
	{
		derta=b*b-4*a*c;
		if(fabs(derta)<=1e-6)
		{	
			printf("��������ȵĸ�:%8.4f\n",-b/(2*a));
		}
		else 
			if(fabs(derta)>1e-6)
			{
				x1=(-b+sqrt(derta))/2*a;
				x2=(-b-sqrt(derta))/2*a;
				printf("�÷����в���ȵ�����ʵ�������ֱ�Ϊ��%8.4f,%8.4f",x1,x2);
			}
			else 
			{
				realpart=-b/(2*a);
				imagpart=sqrt(-derta)/(2*a);
				printf("�÷�����ʵ������������ֱ�Ϊ:%8.4f+%8.4fi",realpart,imagpart);
				printf("%.4f-%.4fi\n",realpart,imagpart);
			}
	}
	return 0;
 } 
