#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<memory.h>
#include<malloc.h>
#include <stdbool.h>
#include<unistd.h>


#define N 100
#define epsilon 0.001
static const int size=N*N;
static double *u;
static double *u_temp;
// u(x,y) is represented as u[y*N+x], where 0<=x,y<=N-1
// 左下角是原点

void initial(double T_bottom, double T_top, double T_left, double T_right){
    u=(double*)malloc(sizeof(double)*(size+1));
    u_temp=(double*)malloc(sizeof(double)*(size+1));
    for(int i=0;i<size;i++){
        u[i]=0.0;
    }
    for(int i=0;i<N;i++){
        u[0*N+i]=T_bottom;
        u[(N-1)*N+i]=T_top;
        u[i*N+0]=T_left;
        u[i*N+N-1]=T_right;
    }
    for(int i=0;i<size;i++){
        u_temp[i]=u[i];
    }
}
/*
对于迭代法的说明:
迭代法的递推公式从数学上来看好像没有什么道理，但是从物理上来看，这恰恰是含时热传导方程将时间离散化的结果。dt就是微元时间。
也就是说，我们要解稳态方程，但是我们借用了非稳态的方程，它在足够长时间内的解近似就是稳态解。u_temp是前一时刻的温度分布,u是这一时刻的温度分布。
前后时刻温度相差很小时循环跳出。
所以这个迭代法意义还是很明确的。
*/
void solve(double dx,double dy,double dt){
    bool loop=true;
    // 这里采用的是迭代法求值，而不是解方程组的方法。所以要设置一个变量表明是否继续迭代，衡量标准取为平均误差。
    // dt 是每次迭代的步长
    do{
        double delta=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<N-1;j++){
                u[i*N+j]=u_temp[i*N+j]+dt*(((u_temp[i*N+j+1]+u_temp[i*N+j-1]-2*u_temp[i*N+j])/(dx*dx))+
                ((u_temp[i*N+j+N]+u_temp[i*N+j-N]-2*u_temp[i*N+j])/(dy*dy)));
            }
        }
        for(int i=0;i<size;i++){
            delta+=fabs(u[i]-u_temp[i]);
            u_temp[i]=u[i];
        }
        printf("%lf\n",delta/(double)size);
        if(delta/(double)size<epsilon){
            loop=false;    // 平均误差小于epsilon 不再循环
        }
    }while(loop==true);
}

void fileOutput(char * path){
    FILE * fp;
    fp=fopen(path,"w");
    for(int i=0;i<N;i++){
        // fprintf(fp,"\n");
        for(int j=0;j<N;j++){
            fprintf(fp,"%d\t%d\t%lf\n",i%N,j%N,u[i*N+j]);
        }
    }
}

int main(){
    char path[100]="D://About_coding/Cfiles/计算物理/homework/homework6/res.txt";
    initial(300,200,450,50);
    solve(0.1,0.1,0.001);
    fileOutput(path);
    return 0;
}