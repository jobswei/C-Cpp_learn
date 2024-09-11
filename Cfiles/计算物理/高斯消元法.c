#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define I 3
#define J 3
int main(){
    double a[I][J]={{2,1,1},{1,3,2},{1,2,2}},b[I]={4,6,5},m[I][J],x[I];
    // 将矩阵化为上三角
    for(int k=0;k!=J-1;k++){
        // 判断是否有为0的对角元
        for(int i=0;i!=I;i++){
            if(a[i][i]==0) break;
        }
        for (int i=k+1;i!=I;i++){
            m[i][k]=a[i][k]/a[k][k];
            b[i]=b[i]-m[i][k]*b[k];
            for(int j=k;j!=J;j++){
                a[i][j]=a[i][j]-m[i][k]*a[k][j];
            }
        }

    }
    // 输出转化后的上三角阵
    for (int i=0;i!=3;i++){

    }
}