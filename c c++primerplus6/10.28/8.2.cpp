#include<stdio.h>
#include<ctype.h>
int main()
{
	int count_upper=0,count_lower=0;
	int ch;
	while((ch=getchar())!=EOF)
		if(isupper(ch))
			count_upper++;
		else if(islower(ch))
			count_lower++;
	printf("The number of uppercase letter %d, Lower case letters%d.\n",count_upper,count_lower);
	
	return 0;
}
