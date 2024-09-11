#include<stdio.h> 
#include<math.h>

void isLeapYear(int leap);
void inputError();
int input();

int main()
{
	int year;
	year=input();
	if(year>0) isLeapYear(year);
	return 0;
}
void isLeapYear(int leap)
{
	if((leap%4==0 && leap%100!=0) || leap%400==0)
	{
		printf("%d is a leap year",leap);
		return;
	}
	printf("%d is a leap year",leap);
} 
int input()
{
	int y=0;
	scanf("%d",&y);
	if(y>0) return y;
	inputError();
	return 0;
}
void inputError()
{
	printf("Invalid input.");
}






