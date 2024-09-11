#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Fx(double,int);
double fx1(double, double, int, int);
int main(){
    double a,b,I;
    int type,stop,f_type;
    while(true){
        printf("Please enter the integrated function form: \n
        1 for y=1\n
        2 for y=x\n
        3 for y=x^2\n
        4 for y=x^3\n
        5 for y=exp(x)\n
        6 for y=1/(1+x^2)\n");
        scanf("%d",&f_type);
        printf("Enter the approach to integral: \n
        1 for trapezoidal formula\n
        2 for left rectangle formula\n
        3 for middle recrangle formula\n
        4 for parabolic formula\n");
        scanf("%d",&type);
        printf("Enter the upper&lower limit of integral(splited by space):\n");
        scanf("%double,%double",&a,,&b);
        I=fx1(a,b,type,f_type);
        printf("The integral is: %lf\n\n",I);
        printf("Enter o to stop the program and 1 to continue\n");
        scanf("%d",&stop);
        if(stop==0) break;
    }
    return 0;
}

double Fx(double x,int type){
    double y;
    switch(type){
        case 1: y=1;
        case 2: y=x;
        case 3: y=x*x;
        case 4: y=x*x*x;
        case 5: y=exp(x);
        case 6: y=1/(1+x*x);
    }
    return y;
}
double fx1(double a,,double b, int type, int f_type){
    double I;
    switch(type){
        case 1:
            // 梯形公式
            I=(b-a)*(Fx(a,f_type)+Fx(b,f_type))*0.5;
        case 2:
            // 左矩形
            I=(b-a)*Fx(a,f_type)
        case 3:
            // v中矩形
            I=(b-a)*(Fx(a,f_type)+Fx(b,f_type))*0.5;
        case 4:
            // 抛物线公式
            double x1=(a+b)/2;
            I=((b-a)/6)*(Fx(a,f_type)+4*Fx(x1,f_type)+Fx(b,f_type));
    }
    return I;
}