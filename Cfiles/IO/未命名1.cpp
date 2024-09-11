#include <stdio.h> 
int main()
{
	char c;
	while(c=getchar()!=EOF)
	{
		if((c>='a'&&c<='z'))
			printf("%c",c-32);
		else
			printf("%c",c);
	}
	return 0;
			
}
