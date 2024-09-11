#include<stdio.h>

#ifndef INTERPOLATION_H
#define INTERPOLATION_H
double Fx(double);   // Fx 为积分函数形式，需要用户自己定义
//double derivative();
double integral(double,double ,int ,int);
double fx1(double, double, int);
#endif

double derivative(double x,double h,int type){
    // 三点差分求导数
    double fhx=Fx(x-h),fx=Fx(x),fxh=Fx(x+h);
    double y;
    switch (type)
    {
    case 1:     // x-h
        y=(1/(2*h))*(-3*fhx+4*fx-fxh);
        break;
    case 2:     // x
        y=(1/(2*h))*(-fhx+fxh);
        break;
    case 3:     // x+h
        y=(1/(2*h))*(fhx-4*fx+3*fxh);
        break; 
    }
    return y;
}

double integral(double a,double b,int type,int n){
    // 差值积分，输入变量为：下限，上限，差值类型，划分区间数
    double I=0;
    b=b-a;
    for (int i=0;i<n;i++){
        I+=fx1(a,a+b/n,type);
        a+=b/n;
    }
    return I;

}
double fx1(double a,double b, int type){
    double I;
    I=0;
    switch(type){
        case 1:
            // 梯形公式
            I=(b-a)*(Fx(a)+Fx(b))*0.5;
            break;
        case 2:
            // 左矩形
            I=(b-a)*Fx(a);
            break;
        case 3:
            // v中矩形
            I=(b-a)*(Fx(a)+Fx(b))*0.5;
            break;
        case 4:
        {
            // 抛物线公式
            double x1=(a+b)/2;
            I=((b-a)/6)*(Fx(a)+4*Fx(x1)+Fx(b));
            break;
            }
    }
    return I;
}