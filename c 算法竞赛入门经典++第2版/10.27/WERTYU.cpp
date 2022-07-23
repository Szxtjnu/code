//WERTYU.cpp
#include<stdio.h>
char s[] = "'1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	int i,c;
	while((c=getchar())!=-1)
	{
		for(i=1;s[i]&&s[i]!=c;i++);//判断语句的作用是为了检验输入的数值是否在给定的s[]中，进而运行下述的判断语句if else. 
		if(s[i]) putchar(s[i-1]);
		else putchar(c);
	}
	return 0;
}
