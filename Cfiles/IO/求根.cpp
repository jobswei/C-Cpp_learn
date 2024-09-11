#include <stdio.h>
#include <math.h>

#define eps 1e-10
int main()
{
	double a,b,c,r1,r2,dt;
	printf("Input 3 real number(a can not be 0): ");
	scanf("%lf%lf%lf",&a,&b,&c);
	dt=b*b-4*a*c;
	if(dt>0.0){
		r1=(-b+sqrt(dt))/(2*a);
		r2=(-b-sqrt(dt))/(2*a);
		printf("The equation has 2 real roots: %f,%f\n",r1,r2);
	}
	else if((dt>-eps)&&(dt<eps)){
		printf("The equation has only 1 real root: %f",-b*(2*a));
	}
	else
		printf("The equation has no real root.");
	
	return 0;
}
