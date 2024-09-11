#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "interpolation.h"

double Fx(double,int);
double fx1(double, double, int, int);
int main(){
    double a,b,I;
    int type,stop,f_type,n;
    while(1){
        printf("""Please enter the integrated function form: \n1 for y=1\n2 for y=x\n3 for y=x^2\n4 for y=x^3\n5 for y=exp(x)\n6 for y=1/(1+x^2)\n");
        scanf("%d",&f_type);
        printf("Enter the approach to integral: \n1 for trapezoidal formula\n2 for left rectangle formula\n3 for middle recrangle formula\n4 for parabolic formula\n");
        scanf("%d",&type);
        printf("Enter the upper&lower limit of integral(splited by space):\n");
        scanf("%double,%double",&a,&b);
        printf("Enter the number of fractions you want to divide the interval into:\n");
        scanf("%d",&n);
        I=0;
        for (int i=0;i<n;i++){
            I+=fx1(a,a+b/n,type,f_type);
            a+=b/n;
        }
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
// double fx1(double a,double b, int type, int f_type){
//     double I;
//     switch(type){
//         case 1:
//             // 梯形公式
//             I=(b-a)*(Fx(a,f_type)+Fx(b,f_type))*0.5;
//         case 2:
//             // 左矩形
//             I=(b-a)*Fx(a,f_type);
//         case 3:
//             // v中矩形
//             I=(b-a)*(Fx(a,f_type)+Fx(b,f_type))*0.5;
//         case 4:
//         {
//             // 抛物线公式
//             double x1=(a+b)/2;
//             I=((b-a)/6)*(Fx(a,f_type)+4*Fx(x1,f_type)+Fx(b,f_type));}
//     }
//     return I;
// }