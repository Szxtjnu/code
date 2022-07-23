#include<stdio.h>
#include<string.h>

int main(int argc,char const* argv[])
{
	void cpy(char *,char *,int);
	char str1 [20],str2 [20];
	int n;
	gets(str1);
	scanf("%d",&n);
	cpy(str1,str2,n);
	printf("%s",str2);
	return 0;
}
void cpy (char *p1,char *p2,int n)
{
	int  idx=0;
	while ( idx<n-1){ //将源字符串指针推到将要复制的那个字符下 
		idx++;
		p1++;
	}
	while( *p1 != '\0'){
		*p2 = *p1;
		p1++;
		p2++;
	}
	*p2 = '\0';
}
