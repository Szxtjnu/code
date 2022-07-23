#include<stdio.h>
long fun(int n)
{
	int i;
	long s=1;
	for(i=1;i<=n;i++)
		s=s*i;
	return s;
}
int main()
{
	long s=0;
	int k,n;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
			s+=fun(k);
			printf("%d\n",s);
		}
	printf("%ld\n",s);
	return 0;
}
