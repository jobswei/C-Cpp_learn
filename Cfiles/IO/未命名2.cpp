#include <stdio.h>
int main()
{	
	int score=0,n=0;
	float sum=0;
	
	
	while(score!=-1)
	{	sum+=score;
		n++;
		scanf("%d",&score); 
		a=getchar();
	}
	
	if(n>0)
		printf("%.2f/%d=%.2f",sum,n,sum/n);
	return 0;
}


