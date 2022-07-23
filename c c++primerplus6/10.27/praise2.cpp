//praise2.cpp
#include<stdio.h>
#include<string.h>
#define PRAISE "You are an extraordinary being."
int main(void)
{
	char name[40];
	printf("What's your name?");
	scanf("%s",name);
	printf("Hello,%s.%s\n",name,PRAISE);
	printf("You name of %d letters occupies %d memory cells.\n",strlen(name),sizeof name);
	printf("The phrase of praise has %d letters",strlen(PRAISE));
	printf("and occupies %d memory cells.\n",sizeof PRAISE);
	return 0;
}
