//four number.cpp

#include<stdio.h>
#include<string.h>
void fournumber(char str1[4],char str2[7])
{
	int i,j;
	for(i=0;i<7;i++)
		str2[i]=' ';
	for(i=0;i<4;i++)
	for(j=2*i;j<i+4;j++)
		if(j%2==0)
		str2[j]=str1[i];		
}
int main()
{
	char str1[4],str2[7];
	gets(str1);
	fournumber(str1,str2);
	printf("%s",str2);
	return 0;
}
