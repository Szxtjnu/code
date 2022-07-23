#include<stdio.h>
int main()
{
	float r,h,l,s,S,V,V1;
	float pi=3.1415926;
	printf("请输入圆面积r，圆柱高h，并用逗号隔开:\n");
	scanf("%f,%f",&r,&h);
	l=2*pi*r;
	s=pi*r*r;
	S=4*pi*r*r;
	V=3.0/4.0*pi*r*r*r;
	V1=s*h;
	printf("圆周长为%.2f\n",l);
	printf("圆面积为%.2f\n",s);
	printf("圆球表面积为%.2f\n",S);
	printf("圆球体积为%.2f\n",V);
	printf("圆柱体积为%.2f\n",V1);
	return 0;
}
