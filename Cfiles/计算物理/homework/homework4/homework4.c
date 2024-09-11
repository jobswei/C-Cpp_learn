#include <stdio.h>
#include <math.h>

#define EPSILON pow(10,-8)   // 精度控制，可根据实际情况修改

double f(double x);       // 非线性方程
double fprime(double x);  // 非线性方程的导数
double newton(double x0); // 牛顿法求解非线性方程的解

int main()
{
    double x0;           // 初始值
    double result;       // 求解结果

    printf("Enter the initial value: ");
    scanf("%lf", &x0);
    // 判断是否需要用牛顿法
    if(fabs(f(x0))<EPSILON){
        printf("The solution is: %lf\n", x0);
        return 0;
    }
    // 判断牛顿法是否适用
    while(fabs(fprime(x0))<pow(10,-3)){
        printf("f'(x0) is too small, please update the intial value: ");
        scanf("%lf",x0);
    }

    result = newton(x0);

    printf("The solution is: %lf\n", result);

    return 0;
}

// 非线性方程
double f(double x)
{
    return cos(x)-pow(x,3);
}

// 非线性方程的导数
double fprime(double x)
{
    // 也可以用interpolation.h中的插值方法求导
    return -sin(x)-3*pow(x,2);
}

// 牛顿法求解非线性方程的解
double newton(double x0)
{
    double x1 = x0 - f(x0) / fprime(x0);
    while (fabs(f(x0)) > EPSILON)
    {
        x0 = x1;
        x1 = x0 - f(x0) / fprime(x0);
    }
    return x1;
}
