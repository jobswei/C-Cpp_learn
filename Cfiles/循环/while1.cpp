#include <stdio.h>
int main()
{
	int a;
	printf("\nInput a score: ");
	
	while(scanf("%d",&a)==0||(a<0||a>100))
		{
			printf("error\n");
			while(getchar()!='\n');	//��ջ����� 
		}
	printf("Good job!");
	return 0;
}
