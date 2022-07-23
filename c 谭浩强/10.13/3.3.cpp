#include<stdio.h>
#include<math.h>
int main()
{
	float d,p,r,m;
	d=300000;
	p=6000;
	r=0.01;
	m=log10(p/(p-d*r))/log10(r+1);
	printf("m=%6.1f\n",m);
	return 0;
}
