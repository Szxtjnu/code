#include<stdio.h>
#include<ctype.h>
int main(void)
{
	int count1=0,count2=0;
	int ch;
	while((ch=getchar())!=0)
	{
		if(ch != '\n')
		{
			if(ispunct(ch)||ch!=' ')
				count1++;
			count2++;
		}
		else break;
	}
	printf("ƽ��ÿ�����ʵ���ĸ��Ϊ%f",1.0*(count2-count1)/count1);
	return 0;
}
