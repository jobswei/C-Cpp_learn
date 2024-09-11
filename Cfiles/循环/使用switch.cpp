#include <stdio.h>

int main()
{
	int score;
	printf("Input score(0`100)");
	scanf("%D",&score);
	
	switch(score/10){
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	default:
		printf("fuck");
	}	//end switch
	
	return 0;
}
