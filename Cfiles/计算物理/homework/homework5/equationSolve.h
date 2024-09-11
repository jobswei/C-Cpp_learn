#include<stdio.h>
#include<math.h>
#ifndef EQUATIONSOLVE_H
#define EQUATIONSOLVE_H
double sovle(double, double, double, double, int);
double Euler_pro(double, double, double, int);
double Euler_pro_pro(double, double, double, int);
double yprime(double, double);
void setepsilon(double);
#endif

double epsilon=0.00001;
void setepsilon(double ep){
    epsilon=ep;
    return;
}
double sovle(double x0, double y0, double h, double xn, int type){
    double num=fabs((xn-x0)/h);// 需要迭代多少步
    int num2=(int)num;
    // 判断能否通过整数步迭代到达目标x
    if((num-num2)>1e-6){// 考虑到数据类型转换的问题，可能会出来1.000000001这样的偏差
        printf("不能通过整数步骤从x0到xn, 输入q退出，输入y为您自动调节h\n");
        char c;
        scanf("%c",&c);
        if(c=='q') return 0;

        h=(xn-x0)/(double)(num2);
    }
    // 判断往正向走还是逆向走
    if(xn<x0) h=-h;
    switch (type){
    case 1:
        return Euler_pro(x0,y0,h,num2);
    case 2:
        return Euler_pro_pro(x0,y0,h,num2);
    default:
        printf("您输入的type有误");
        return 0;
    }

}

double Euler_pro(double x0, double y0, double h, int num){
    double xn=x0;
    double yn=y0;
    for(int i=0;i<num;i++){
        double yn1=yn+h*yprime(xn,yn);
        yn+=(double)h/2*(yprime(xn,yn)+yprime(xn+h,yn1));
        xn+=h;
    }
    return yn;
}
double Euler_pro_pro(double x0, double y0, double h, int num){
    double xn=x0;
    double yn=y0;
    for(int i=0;i<num;i++){
        double yn1=yn+h*yprime(xn,yn);
        // 对yn+1进行迭代，直到误差小于epsilon
        while(1){
            double yn1s=yn+h/2*(yprime(xn,yn)+yprime(xn+h,yn1));
            if (yn1s-yn1<epsilon) break;
            yn1=yn1s;
        }
        
        yn+=(double)h/2*(yprime(xn,yn)+yprime(xn+h,yn1));
        xn+=h;
    }
    return yn;
}

