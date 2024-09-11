#include <stdio.h>
int main()
{
	int a,b;
	double d;
	scanf("%d%d",&a,&b);
	d=(double)(a)/b;
	printf("%d/%d=%.2f\n",a,b,d);
	return 0;
}
