#include<stdio.h>
int main()
{
	int count=0;
	char ch;
	while((ch=getchar())!=EOF)
		count++;
	printf("There are %d chars.",count);
	
	return 0;
 } 
