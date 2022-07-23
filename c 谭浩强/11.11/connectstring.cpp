//connect string.cpp

#include<stdio.h>
#include<string.h>
#define N 100
void connectstring(char str1[],char str2[],char str[])
{
	int i,j;
	for(i=0;str1[i]!='\0';i++)
		str[i]=str1[i];
	for(j=0;str2[j]!='\0';j++)
		str[i+j]=str2[j];
	str[i+j]='\0'; 
}
int main()
{
	char str1[N],str[N],str2[N];
	gets(str1);
	gets(str2);
	connectstring(str1,str2,str);
	printf("%s",str);
	return 0;
}
