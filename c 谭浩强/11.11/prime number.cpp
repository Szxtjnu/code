//prime number.cpp

#include<stdio.h>
#include<math.h>
int prime(int num)
{
	int flag=1,i;
	for(i=2;i<=sqrt(num)&&flag==1;i++)
	{
		if(num%i==0)
		flag=0;
	}
	return(flag);
}
int main()
{
	int num;
	scanf("%d",&num);
	if(prime(num))
		printf("%d is a prime number.",num);
	else
		printf("%d is not a prime number.",num);
	return 0;
}
