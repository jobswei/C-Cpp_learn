#include <stdio.h>

int main()
{
	int a,b;
	double d;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(b==0)
			printf("devided by zero!\n");
		else
			{
				d=(double)(a)/b;
				printf("%d/%d=%.2f\n",a,b,d);
			}
	}
	
	return 0;
}

