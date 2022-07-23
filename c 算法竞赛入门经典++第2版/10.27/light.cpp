#include<stdio.h>
#include<string.h>
#define maxn 1005
int a[maxn];
int main()
{
	int k,n,first=1;
	memset(a,0,sizeof(0));//将所有灯的状态初始化为关 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)/*i=1时，j++，将所有灯的状态初始化为开
						   i++时，j%i代表k的倍数的灯*/ 
	  for(int j=1;j<=n;j++)
	    if(j%i==0) a[j]=!a[j];
	for(int i=1;i<=n;i++)
	  if(a[i])
	  {
	  	if(first)  first=0;
	  	else printf(" ");
		printf("%d",i);
	  }
	return 0;
 } 
