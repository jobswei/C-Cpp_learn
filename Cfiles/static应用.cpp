//static ÓÃÀı£ºÇó½×³Ë
#include<stdio.h>
int fun(int);
int main()
{
	int i;
	for(i=1;i<=5;i++)
		printf("%d! = %d\n",i,fun(i));
	return 0;
} 
int fun(int a)
{
	static int m=1;
	m*=a;
	return m;
}
