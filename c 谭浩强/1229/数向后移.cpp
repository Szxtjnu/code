#include<stdio.h>
/*在对一维数组的顺序进行更改的时候
只需要将最后一位的数字保存在缓存中
然后将每一位数字向后/前移位即可*/ 
void swap(int *array,int n,int m)
{
	int *p,idx_end;
	idx_end = *(array+n-1);
	for(p=array+n-1; p>array; p--){
		*p = *(p-1);
	}
	*array = idx_end;
	m--;
	if(m>0){
		swap(array,n,m);
	}
 } 
int main(int argc,char const *acgv[])
{
	int number[20],n,m,i;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&number[i]);
	}
	scanf("%d",&m);
	swap(number,n,m);
	for(i=0; i<n; i++){
		printf("%d  ",number[i]);
	}
	return 0;
}
