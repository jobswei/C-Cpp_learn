#include<stdio.h>
#include<math.h>
#include "equationSolve.h"

double y(double);

int main(){
    printf("x\t精确y\t\t改进欧拉方法y\t误差\t梯形方法y\t误差\n");
    for (int i =1 ;i<6;i++){
        double xi=0+0.1*i;
        double y1=sovle(0, 0, 0.1, xi, 1);
        double y2=sovle(0, 0, 0.1, xi, 2);
        double y3=y(0+0.1*i);
        double delta1=fabs((y1-y3)/y3)*100;
        double delta2=fabs((y2-y3)/y3)*100;
        printf("%.2lf\t%lf\t%lf\t%.2lf%%\t%lf\t%.2lf%%\n",xi,y3,y1,delta1,y2,delta2);
    }
    
}

double yprime(double x, double y){
    return x*x+x-y;
}
double y(double x){
    return -exp(-x)+x*x-x+1;
}
