#include<stdio.h>
int main(int argc,char const *argv[])
{
	void sort (char *p, int m);
	int i,n;
	char *p, num[20];
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&num[i]);
	}
	p = &num[0];
	sort (p,n);
	for(i=0; i<n; i++){
		printf("%d  ",num[i]);
	}
	return 0;
 } 
void sort (char *p,int m)
{
	char *p1,*p2,temp;
	for(int i=0; i<(m/2); i++){
		p1 = p + i;
		p2 = p + (m-1-i);
		temp = *p1; *p1 = *p2; *p2 = temp;
	}
	
}
