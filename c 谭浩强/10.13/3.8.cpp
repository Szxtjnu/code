#include<stdio.h>
int main()
{
	char r1,r2;
	printf("�����������ַ� c1,c2:\n");
	r1=getchar();
	r2=getchar();
	printf("��putchar���������Ϊ��");
	putchar(r1);
	putchar(r2);
	printf("\n");
	printf("��printf���������Ϊ��");
	printf("%c",r1);
	printf("%c",r2);
	return 0;
}
