#include<stdio.h>

int main(int argc,char const* argv[])
{
	void move (int *pointer);
	int a[3][3],*p;
	printf("input matricx:\n");
	for(int i=0;i<3;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	p=&a[0][0];
	move(p);
	printf("Now matrix:\n");
	for(int i=0; i<3; i++){
		printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
	}
	return 0;
}
void move(int *pointer)
{
	int t;
	for(int i=0; i<3; i++){
		for(int j=i; j<3; j++){
			t= *(pointer+3*i+j);
			*(pointer+3*i+j) = *(pointer+3*j+i);
			*(pointer+3*j+i) =t;
		}
		
	}
}
