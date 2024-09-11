#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"selfRand.h"
/*
这个版本是上周的作业要求，就是要求给定置信区间，要求pi的值落在置信区间内
*/
#define getRand() rand()/(RAND_MAX+1.0)
#define Lambda 1.96
#define epsilon0 0.0001

long long int Monte(long long int);
double dist(double,double);
long double Epsilon(long long int,long long int);

int main(){
    long long int N=0,M=0;
    long long int n=10;
    long double pi=0;
    long double epsilon=0;

    clock_t start_time,end_time;
    start_time=clock();
    do{
        N+=n;
        M+=Monte(n);
        pi=4*(long double)M/N;

        epsilon=Epsilon(M,N);
    }while(epsilon>epsilon0);
    end_time=clock();
    
    // printf输出long double 有bug
    __mingw_printf("(M=%lld,N=%lld)\npi=%.12Lf\n",M,N,pi);
    __mingw_printf("epsilon=%.12Lf <= epsilon0=%lf\n",epsilon,epsilon0);
    __mingw_printf("用时: %lf \n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    FILE *fp = NULL;
    // fp = fopen("./Monte Result3.1.txt", "w+");
    fp = fopen("D://About_coding/Cfiles/计算物理/homework/Monte Result.txt", "w+");
    __mingw_fprintf(fp, "(M=%lld,N=%lld)\npi=%.12Lf\n",M,N,pi);
    __mingw_fprintf(fp,"epsilon=%.12Lf <= epsilon0=%lf\n",epsilon,epsilon0);
    __mingw_fprintf(fp,"用时: %lf \n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fclose(fp);
    return 0;
}

long long int Monte(long long int n){
    long long int m=0;
    for(int i=0; i<n; i++){
        double x1=getRand();
        double x2=getRand();
        if (dist(x1,x2)<=0.25) m++;
    }
    return m;
}

double dist(double x1,double x2){
    return pow(x1-0.5,2)+pow(x2-0.5,2);
}

long double Epsilon(long long int M,long long int N){
    long double sigma=sqrt((double)M/N-pow(M/N,2));
    return (long double) Lambda*sigma/sqrt(N);
}