//Hanoi.cpp

#include<stdio.h>
void hanoi(int n,char A,char B,char C)
{
	if(n<=1)
	{
		printf("move %c to %c\n",A,C);
		return ;
	}
	hanoi(n-1,A,C,B);
	printf("move %c to %c\n",A,C);
	hanoi(n-1,B,A,C);
}
int main()
{
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}
