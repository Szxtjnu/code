#include<stdio.h>

int main(int argc,char const *argv[])
{
	void sort (int *a);
	int *p,i,a[10];
	p = a;
	for(i = 0;i < 10;i++){
		scanf("%d",&a[i]);
	}
	sort(a);
	for(i = 0;i < 10;i++){
		printf("%d",a[i]);
	}
	return 0;
}
void sort ( int *a)
{
	int temp;
	for(int i = 0;i < 10;i++){
		for(int j=i; j<9; j++){
			if(a[j]>a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}
