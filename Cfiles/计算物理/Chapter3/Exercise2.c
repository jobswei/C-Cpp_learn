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
	printf("��������㲽��\n");
	scanf("%lf", &h);
	printf("�����빫ʽ���ͣ�\n 1��f(x + h)��f(x)��ֵ����x���ĵ���\t 2��f(x)��f(x - h)��ֵ����x���ĵ���\n");
	scanf("%d", &type);
	if (type==1)
	{
		printf("����������f(x + h)��f(x)��ֵ\n");
		scanf("%lf%lf", &fxh, &fx);
		y = fx1(fxh, fx, h, type);
	}
	else if (type == 2)
	{
		printf("����������f(x)��f(x - h)��ֵ\n");
		scanf("%lf%lf", &fxh, & fx);
		y = fx1(fxh, fx, h, type);
	}
	printf("������ֵΪ��%lf", y);
	system("pause");
	return 0;
}