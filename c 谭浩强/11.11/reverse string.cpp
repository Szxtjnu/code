//Reverse string.cpp

#include<stdio.h>
#include<string.h>
void reversestring(char str[]) 
{
	char temp;
	int i,j;
	for(i=0,j=strlen(str);i<(j/2);i++,j--)
	{
		temp=str[i];
		str[i]=str[j-1];
		str[j-1]=temp;
	}
}
int main()
{
	char str[100];
	scanf("%s",&str);
	reversestring(str);
	printf("%s",str);
	return 0;
}
