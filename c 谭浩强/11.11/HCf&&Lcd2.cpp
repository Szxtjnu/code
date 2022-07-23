//HCf&&LCD.cpp

#include<stdio.h>
int Hcf,Lcd;
void hcf(int a,int b)
{
	int temp,remainder;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while((remainder=a%b)!=0)
	{
		a=b;
		b=remainder;
	}
	Hcf=b;
}
void lcd(int a,int b)
{
	Lcd=a*b/Hcf;
}
int main()
{
	int u,v;
	scanf("%d,%d",&u,&v);
	hcf(u,v);
	lcd(u,v);
	printf("HCF=%d\n",Hcf);
	printf("LCD=%d\n",Lcd);
	return 0;
}
