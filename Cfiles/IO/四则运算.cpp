#include <stdio.h>
#include<math.h>

int main()
{
	char op; double x,y,r;
	scanf("%c%lf%lf",&op,&x,&y);
	
	if('+'==op)		r=x+y;
	else if('-'==op)	r=x-y;
	else if('*'==op)	r=x*y;
	else if(('/'==op)&&(y>=1e-10))	r=x/y;
	
	else{
		printf("invalid expression %6.2f%c%6.2f\n",x,op,y);
		return 1;
	}
	printf("%6.2f%c%6.2f=%12.4f\n",x,op,y,r);
	return 0;
}
