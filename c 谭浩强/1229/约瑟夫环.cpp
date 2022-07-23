#include<stdio.h>
int main(int argc,char const *argv[])
{
	int i,k,m,n,num[50],*p;
	printf("\n人数: n= ");
	scanf("%d",&n);
	p = num;
	for(int i=0; i<n; i++){
		*(p+i) = i+1; //给每个人编号 
	}
	i=0; // 每次循环时计数变量 
	k=0; // 按1，2，3报数时的计数变量 
	m=0; // 退出人数 
	while (m<n-1){
		if( *(p+i) != 0){
			k++;
		}
		if( k == 3){  //取余也行 
			*(p+i) = 0;
			k = 0;
			m++;
		}
		i++;
		if( i == n){
			i = 0;
		}
	}
	while (*p == 0) p++;
	printf("第%d个",*p);
	return 0;
}
