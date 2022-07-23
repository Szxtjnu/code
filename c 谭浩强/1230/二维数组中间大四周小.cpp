#include<stdio.h>

int main(int argc,char const* argv[])
{
	void change( int *p);
	int a[5][5],*p;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf("%d",&a[i][j]);
		}
	}
	p = &a[0][0];
	change(p);
	printf("Now,matrix:\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
 } 
void swap( int *a,int *b)
{
	int temp;
	temp=*a; *a=*b; *b=temp;
}
void change (int *p)
{
	int i,j,temp;
	int *pmax,*pmin;
	pmax = p;
	pmin = p;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if( *pmin > *(p+i*5+j)) pmin = (p+i*5+j);
			if( *pmax < *(p+i*5+j)) pmax = (p+i*5+j); 
		}
	}
	swap( (p+12), pmax);
	swap( p, pmin);
	pmin = p+1;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if( i==0 && j==0 ) continue;
			if( *pmin > *(p+5*i+j)) pmin = p+5*i+j;
		}
	}
	swap( (p+4),pmin);
	pmin = p+1;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(( i==0 && j==0 ) || ( i==0 && j==4))continue;
			if( *pmin > *(p+5*i+j)) pmin = p+5*i+j;
		}
	}
	swap( (p+20),pmin);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(( i==0 && j==0 ) || ( i==0 && j==4) || ( i==4 && j==0))continue;
			if( *pmin > *(p+5*i+j)) pmin = p+5*i+j;
		}
	}
	swap( (p+24),pmin);
}

