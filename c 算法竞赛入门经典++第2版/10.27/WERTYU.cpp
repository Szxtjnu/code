//WERTYU.cpp
#include<stdio.h>
char s[] = "'1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	int i,c;
	while((c=getchar())!=-1)
	{
		for(i=1;s[i]&&s[i]!=c;i++);//�ж�����������Ϊ�˼����������ֵ�Ƿ��ڸ�����s[]�У����������������ж����if else. 
		if(s[i]) putchar(s[i-1]);
		else putchar(c);
	}
	return 0;
}
