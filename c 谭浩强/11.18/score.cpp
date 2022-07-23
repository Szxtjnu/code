//score.cpp

#include<stdio.h>
#define N 10
#define M 5
float score [N][M];
float a_stu[N],a_cour[M];
int r,c;


void average(void)
{
	float s;
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<N;j++)
	    	s+=score[i][j];
	    a_stu[i]=s/5.0;
	}
}
void input_stu(void)
{
	for(int i=0;i<N;i++)
	{
		printf("\nInput score of student %2d:\n",i+1);
		for(int j=0;j<M;j++)
		  scanf("%f",&score[i][j]);
	}
}
void aver_class(void)
{
	float s;
	for(int j=0;j<M;j++)
	{
		s=0;
		for(int i=0;i<N;i++)
		  s+=score[i][j];
		a_cour[j]=s/(float)N;
	}
}
float highest(void)
{
	float high;
	high=score[0][0];
	for(int i=0;i<N;i++)
	  for(int j=0;j<M;j++)
	    if(score[i][j]>high)
	    {
	    	high=score[i][j];
	    	r=i+1;
	    	c=j+1;
		}
	return(high);
}
float s_var(void)
{
	float sumx=0.0,sumxn=0.0;
	for(int i=0;i<N;i++)
	{
		sumx+=a_stu[i]*a_stu[i];
		sumx+=a_stu[i];
	}
	return(sumx/N-(sumx/N)*(sumx/N));
}
int main()
{
	float h;
	input_stu();
	average();
	aver_class();
	printf("\n  NO.   cour1   cour2   cour3   cour4   cour5   aver\n");
	for(int i=0;i<N;i++)
	{
		printf("\nNO %2d",i+1);
		for(int j=0;j<M;j++)
		  printf("%8.2f",score[i][j]);
		printf("%8.2f\n",a_stu[i]);
	}
	printf("\naverage:");
	for(int j=0;j<M;j++)
		printf("%8.2f\n",a_cour[j]);
	printf("\n");
	h=highest();
	printf("highest:%7.2f   NO.%2d  course %2d\n",h,r,c);
	printf("variance %8.2f\n",s_var());
	return 0;
}
