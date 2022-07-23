#include<stdio.h>

int main(int argc,char const *argv[])
{
	int length (char *p);
	int len;
	char str[20];
	printf("Input string :");
	scanf("%s",&str);
	len=length(str);
	printf("The length of string is %d.\n",len);
	return 0;
 } 
int length (char *p)
{
	int n=0;
	while ( *p != '\0'){
		n++;
		p++;
	}
	return (n);
}
