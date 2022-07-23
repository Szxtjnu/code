#include<stdio.h>
int main()
{
	char r1,r2;
	printf("请输入两个字符 c1,c2:\n");
	r1=getchar();
	r2=getchar();
	printf("用putchar语句输出结果为：");
	putchar(r1);
	putchar(r2);
	printf("\n");
	printf("用printf语句输出结果为：");
	printf("%c",r1);
	printf("%c",r2);
	return 0;
}
