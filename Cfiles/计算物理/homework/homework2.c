#include<stdio.h>
#include<math.h>
#include "interpolation.h"

int main(){
    double x=1.1,h=0.1;
    double fhx=derivative(x,h,1);
    double fx=derivative(x,h,2);
    double fxh=derivative(x,h,3);
    printf("f(x)=1/(1+x)^2 的导数如下: \n f'(1.00)=%lf \n f'(1.10)=%lf \n f'(1.20)=%lf",fhx,fx,fxh);    return 0;
}

double Fx(double x){
    double y=1/pow((1+x),2);
    return y;
}