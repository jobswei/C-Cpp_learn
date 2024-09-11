#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx1(double x[3], double h, int type);
double fx1(double x[3], double h, int type)
{
    double y;
    if (type == 1)
    {
        y = (x[2] - x[1]) / h;
        return y;
    }
    else if (type == 2)
    {
        y = (x[1] - x[0]) / h;
        return y;
    }
    else if (type == 3)
    {
        y = (x[2] - x[0]) / (2 * h);
        return y;
    }
    else
    {
        printf("Error: type must be 1, 2 or 3");
        return 0;
    }
}

int main()
{
    double h, x[3], y, y2, yh[3];
    int i, type;
    printf("请输入计算步长\n");
    scanf("%lf", &h);
    x[0] = 1.15 - h;
    x[1] = 1.15;
    x[2] = 1.15 + h;
    for (i = 0; i < 3; i++)
    {
        yh[i] = exp(x[i]);
    }
    y = fx1(yh, h, 1);
    y2 = fx1(yh, h, 3);
    printf("用前向差商求出的导数值为：\n %.12f\n", y);
    printf("用中心差商求出的导数值为：\n %.12f\n", y2);
    printf("x-h, x, x+h处求导的真实值为：\n %.12f\n %.12f\n %.12f\n", exp(x[0]), exp(x[1]), exp(x[2]));
    printf("用前向差商求出的导数值与真实值的差为：\n %.12f\n", exp(x[1]) - y);
    printf("用中心差商求出的导数值与真实值的差为：\n %.12f\n", exp(x[1]) - y2);
    system("pause");
    return 0;
}
