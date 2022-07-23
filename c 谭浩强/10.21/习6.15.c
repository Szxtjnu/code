#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100];
	int i;
	scanf("%s",s1);
	for(i=0;i<=strlen(s1);i++)
	{
		s2[i]=s1[i];
	}
	printf("%s",s2);
	return 0;
 } 
