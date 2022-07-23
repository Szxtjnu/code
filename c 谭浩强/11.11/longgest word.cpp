//longest word.cpp

#include<stdio.h>
#include<string.h>
int alphabetic(char c)
{
	if((c>='a'&&c<='z')||(c>'A'&&c<='Z'))
		return(1);
	else
		return(0);
 } 
int longest(char str[])
{
	int len=0,i,lenth=0,flag=1,place=0,point;
	for(i=0;i<=strlen(str);i++)
	{
		if(alphabetic(str[i]))
		if(flag)
		{
			point=i;
			flag=0;
		}
		else len++;
		else{
			flag=1;
			if(len>=lenth)
			{
				lenth=len;
				len=0;
				place=point;
			}
		}
	}
	return(place);
}
int main()
{
	char line[100];
	gets(line);
	for(int i=longest(line);alphabetic(line[i]);i++)
	{
		printf("%c",line[i]);
	}
	printf("\n");
	return 0;
}
