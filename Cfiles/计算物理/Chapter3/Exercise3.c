#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx1(double fx0, double fx1, double fx2, double h, int type);
double fx1(double fx0, double fx1, double fx2, double h, int type)
{
	double y, x;
	if (type == 1)
	{
		y = (1 / (2 * h)) * (-3 * fx0 + 4 * fx1 - fx2);
		x = (1.0 / (2.0 * h)) * (-3.0 * fx0 + 4.0 * fx1 - fx2);
	}
	else if (type == 2)
	{
		y = (1 / (2 * h)) * (-fx0 + fx2);
	}
	else if (type == 3)
	{
		y = (1 / (2 * h)) * (fx0 - 4 * fx1 + 3 * fx2);
	}
	else
	{
		printf("Error: type must be 1, 2 or 3");
	}
	return y;
}

double fx2(double fx0, double fx1, double fx2, double h);
double fx2(double fx0, double fx1, double fx2, double h)
{
	double y;
	y = (1 / (h * h)) * (fx0 - 2 * fx1 + fx2);
	return y;
}

int main()
{
	double h, fhx, fx, fxh, y, y2;
	int type;
	printf("��������㲽��\n");
	scanf(" %lf", &h);
	printf("�����빫ʽ���ͣ�\n 1��ǰ����̹�ʽ\t 2�����Ĳ��̹�ʽ\t 3��������̹�ʽ\n");
	scanf(" %d", &type);
	printf("����������f(x - h)��f(x)��f(x+h)��ֵ\n");
	scanf(" %lf %lf %lf", &fhx, &fx, &fxh);
	if (type == 1)
	{
		y = fx1(fhx, fx, fxh, h, type);
		y2 = fx2(fhx, fx, fxh, h);
	}
	else if (type == 2)
	{
		y = fx1(fhx, fx, fxh, h, type);
		y2 = fx2(fhx, fx, fxh, h);
	}
	else if (type == 3)
	{
		y = fx1(fhx, fx, fxh, h, type);
		y2 = fx2(fhx, fx, fxh, h);
	}
	printf("������ֵΪ��%lf", y);
	printf("������׵���ֵΪ��%lf", y2);
	system("pause");
	return 0;
}
