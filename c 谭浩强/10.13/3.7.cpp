#include<stdio.h>
int main()
{
	float r,h,l,s,S,V,V1;
	float pi=3.1415926;
	printf("������Բ���r��Բ����h�����ö��Ÿ���:\n");
	scanf("%f,%f",&r,&h);
	l=2*pi*r;
	s=pi*r*r;
	S=4*pi*r*r;
	V=3.0/4.0*pi*r*r*r;
	V1=s*h;
	printf("Բ�ܳ�Ϊ%.2f\n",l);
	printf("Բ���Ϊ%.2f\n",s);
	printf("Բ������Ϊ%.2f\n",S);
	printf("Բ�����Ϊ%.2f\n",V);
	printf("Բ�����Ϊ%.2f\n",V1);
	return 0;
}
