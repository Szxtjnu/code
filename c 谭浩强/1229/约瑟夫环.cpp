#include<stdio.h>
int main(int argc,char const *argv[])
{
	int i,k,m,n,num[50],*p;
	printf("\n����: n= ");
	scanf("%d",&n);
	p = num;
	for(int i=0; i<n; i++){
		*(p+i) = i+1; //��ÿ���˱�� 
	}
	i=0; // ÿ��ѭ��ʱ�������� 
	k=0; // ��1��2��3����ʱ�ļ������� 
	m=0; // �˳����� 
	while (m<n-1){
		if( *(p+i) != 0){
			k++;
		}
		if( k == 3){  //ȡ��Ҳ�� 
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
	printf("��%d��",*p);
	return 0;
}
