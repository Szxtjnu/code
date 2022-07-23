#include<stdio.h>

int a[10];

void inPut ( int *a)
{
	for( int i=0; i<10; i++){
		scanf("%d",&a[i]);
	}
 }
 
void outPut ( int *a)
{
	for( int i=0; i<10; i++){
		printf("%d  ",a[i]);
	}
}

int swap (int *a)
{
	int *max, *min, *p, temp;
	max = min = a;
	for(p=a+1; p<(a+10); p++){
		if(*p > *max){
			max = p;
		}
		else if(*p < *min){
			min = p;
		}
	}
	temp = *a; *a = *min; *min =temp;
	if( max == a){
		max = min;
	}
	temp = *(a+9); *(a+9) = *max; *max = temp;
}

int main(int argc, char const* argv[])
{
	inPut(a);
	swap(a);
	outPut(a);
	return 0;
}

