#include <stdio.h>
int main()
{
	//½×³Ë 
	int i,r,n=6;
	for(r=i=1;i<=n;i++)	r*=i;
	printf("%d\n",r);
	
	int a=-24,b=48;
	if(0==b)
		{
			printf("gcd is£º %d\n",a);
			return 0;
		}
	for(r=a%b;r!=0;r=a%b)
		{
			a=b;
			b=r;
		}
		printf("gcd is£º %d\n",b<0 ? -b:b);
	return 0;
}
