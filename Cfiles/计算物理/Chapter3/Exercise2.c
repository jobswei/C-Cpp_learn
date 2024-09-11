#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fx1(double fxh, double fx, double h, int type);
double fx1(double fxh, double fx, double h, int type){
	double y;
	if (type==1){
		y = (fxh - fx) / h;
		return y;
	}
	else if (type==2){
		y = (fxh - fx) / h;
		return y;
	}
	else{
		printf("Error: type must be 1, 2 or 3");
		return 0;
	}
}
int main()
{
	double h, fx, fxh, y;
	int type;
	printf("请输入计算步长\n");
	scanf("%lf", &h);
	printf("请输入公式类型：\n 1、f(x + h)和f(x)的值计算x处的导数\t 2、f(x)和f(x - h)的值计算x处的导数\n");
	scanf("%d", &type);
	if (type==1)
	{
		printf("请依次输入f(x + h)和f(x)的值\n");
		scanf("%lf%lf", &fxh, &fx);
		y = fx1(fxh, fx, h, type);
	}
	else if (type == 2)
	{
		printf("请依次输入f(x)和f(x - h)的值\n");
		scanf("%lf%lf", &fxh, & fx);
		y = fx1(fxh, fx, h, type);
	}
	printf("所求导数值为：%lf", y);
	system("pause");
	return 0;
}