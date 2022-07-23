#include<stdio.h>
#include<math.h>
int main(int argc,char const* argv[])
{
	float inte(float(*)(float),float,float,int);
	float fsin(float);
	float fcos(float);
	float fexp(float);
	float a1,b1,a2,b2,a3,b3,c,(*p)(float);
	int n = 20;
	scanf("%f,%f",&a1,&b1);
	p = fsin;
	c = inte(p,a1,b1,n);
	printf("%f\n",c);
	return 0;
}
float inte(float (*p)(float),float a, float b, int n)
{
	int i;
	float x,h,s;
	h = (b-a)/n;
	x = a; s = 0;
	for(i=1; i<=n ;i++){
		x = x+h;
		s = s+(*p)(x)*h;
	}
	return(s);
}
float fsin(float x)
{
	return sin(x);
}
