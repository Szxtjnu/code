//3n+1.cpp
#include<stdio.h>
int main()
{
	int count=0;
	long long n;
	scanf("%lld",&n);
	while(n>1)
	{
		if(n%2!=0)
		n=3*n+1;
		else n=n/2;
		count++;
	}
	printf("%d\n",count);
	return 0;
}
