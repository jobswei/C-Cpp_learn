#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"selfRand.h"
/*
这个版本是本周的最新要求，使用自己的随机数，给定投针次数N，求pi
*/
// #define getRand() rand()/(RAND_MAX+1.0)
#define getRand() (double)LCRand()/(LC_MAX) // 平方取中法100次之内就会收敛到同一个数，所以使用线性同余法
#define N 500000

double dist(double,double);

int main(){
    int n=1000;// 总共记录1000个点
    int delta=N/n;
    int m=0;
    double pi=0.0;
    FILE *fp = NULL;

    clock_t start_time,end_time;
    start_time=clock();

    fp = fopen("D://About_coding/Cfiles/计算物理/homework/homework3/pi array.txt", "w+");
    for(int i=1; i<=N; i++){
        double x1=getRand();
        double x2=getRand();
        if (dist(x1,x2)<=0.25) m++;
        
        if(i%delta==0){
            pi=(double)4*m/i;
            fprintf(fp,"%.6lf\n",pi);
        }
    }
    
    end_time=clock();
    
    printf("pi=%.6lf\n",pi);
    printf("用时: %lf \n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    fclose(fp);
    return 0;
}

double dist(double x1,double x2){
    return pow(x1-0.5,2)+pow(x2-0.5,2);
}