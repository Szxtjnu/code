#include<stdio.h>
int main(int argc,char const * argv[])
{

	int num_sum = 0;
	int flag = 0; 
	int a[10]={};
	char str[30];
	gets(str);
	char *p = &str[0];
	char z;
	int i = 0,j = 0;
	while ( (z=*(p+i) )!= '\0'){
		if ( z >= '0' && z <= '9'){
			num_sum = num_sum*10 + (z-'0');
			flag = 1;
		}
		else{
			if( flag == 1){
				a[j++] = num_sum;
				num_sum = 0;
			}
			flag = 0;
		}
		i++;
	}
	if( flag == 1){
		a[j++] = num_sum;
	}
	a[j] = '\0';
	for(int i=0;i<j;i++)
	{
		printf("%d  ",a[i]);
	}
	
	return 0;
}
