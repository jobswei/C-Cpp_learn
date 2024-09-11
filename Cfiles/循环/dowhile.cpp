#include <stdio.h>
int main()
{
	int a=24,b=48,r;
	do
	{
		r=a%b;
		a=b;	b=r;
	} while (r!=0);
}
