#include<stdio.h>

int main(int argc,char const *argv[])
{
	char str1[30],str2[30];
	gets(str1);
	gets(str2);
	char *p1, *p2;
	p1 = &str1[0];
	p2 = &str2[0];
	while( (*p1 == *p2) && *p1 != '\0'){
		p1++;
		p2++;
	}
	if ( *p1 != *p2){
		printf("%d",(*p1-*p2));
	}
	if ( *p1 == '\0'){
		printf("0");
	}
	return 0;
}
