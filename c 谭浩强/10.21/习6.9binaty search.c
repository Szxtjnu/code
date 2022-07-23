#include<stdio.h>
#define N 15
int main()
{
	int i=1,a[15];
	printf("Enter Data:\n");
	scanf("%d",&a[0]);
	while(i<N)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])
		{
			i++;
		}
		else
			printf("Plese enter this data again:\n");		
	}
	printf("\n");
	int flag,aim,mid;
	printf("input number to look for:\n");
	scanf("%d",&aim);
	int sign=0,top=0,bot=N-1,loca=0;
	if((aim<a[0])||(aim>a[N-1]))
		loca=-1;
	while((!sign)&&(top<=bot))
	{
		mid=(top+bot)/2;
		if(aim==a[mid])
		{
			loca=mid;
			printf("Has found %d,its position is %d\n",aim,loca+1);
			sign=1;
		}
		else if(aim<a[mid])
			bot=mid-1;
		else
			top=mid+1;
	}
	if(!sign||(loca==-1))
		printf("Cannot find %d.\n",aim);
	return 0;
}
