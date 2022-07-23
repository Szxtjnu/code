#include<stdio.h>
int main()
{
	char str[3][80];
	int Acount=0,acount=0,space=0,other=0;
	int i,j;
	for(j=0;j<3;j++)
	gets(str[j]);
	for(j=0;j<3;j++)
	{
		for(i=0;i<80&&(str[j][i]!=EOF);i++)
		{
			if(str[j][i]==' ')  space++;
			else if(str[j][i]>='a'&&str[j][i]<='z')  acount++;
			else if(str[j][i]>='A'&&str[j][i]<='Z')  Acount++;
			else other++;
		}
	  } 
	printf("%d,%d,%d,%d",Acount,acount,space,other);
	return 0; 
 } 
