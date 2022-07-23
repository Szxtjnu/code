#include<stdio.h>
#include<math.h>
float x1,x2,disc,p,q;
void greater_than_zero(float a,float b)
{
	x1=(-b+sqrt(disc))/(2*a);
	x2=(-b-sqrt(disc))/(2*a);
}
void equal_to_zero(float a,float b)
{
	x1=x2=(-b)/(2*a);
}
void smaller_than_zero(float a,float b)
{
	p=-b/(2*a);
	q=sqrt(-disc)/(2*a);
}
int main()
{
	scanf("%f%f%f",&a,&b,%c);
	disc=b*b-4*a*c;
	if(disc>0)
	{
		great_than_zero(a,b);
		printf("%f%f")
	}
 } 
