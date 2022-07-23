#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i;  
    scanf("%s",&s);  
    for (i = 0; s[i] != '\0'; i++)  
    {  
        if ('a' <= s[i] &&s[i]<= 'z')  
            printf("%c", s[i] - 32);  

        else  
        printf("%c", s[i]);  
    }  
    return 0;  
 } 
