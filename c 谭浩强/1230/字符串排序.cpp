#include<stdio.h>
#include<string.h>

int main(int argc,char const* argv[])
{
	void sort ( char s[][6]);
	char str[10][6];
	for(int i=0; i<10; i++){
		scanf("%s",&str[i]);
	}
	sort(str);
	for(int i=0; i<10; i++){
		printf("%s\n",str[i]);
	}
	return 0;
}
void sort ( char s[10][6])
{
	int i,j;
	char *p,temp[10];
	p=temp;
	for(int i=0; i<9; i++){
		for(int j=0; j<9-i; j++){
			if( strcmp(s[j],s[j+1])>0){
				strcpy( p,s[j]);
				strcpy( s[j],s[j+1]);
				strcpy( s[j+1],p);
			}
		}
	}
}
