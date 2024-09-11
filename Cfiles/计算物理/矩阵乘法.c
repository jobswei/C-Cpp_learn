#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ArrayNum(x) (sizeof(x) / sizeof(x[0]))

void InputMatrix(int,int, int **);
void DispMatrix(int,int, int **);
int main(){
    int i,j,k;
    int row1,column1,row2,column2;
    printf("number of rows&columns for matrix A: \n");
    scanf("%d %d",&row1,&column1);
    printf("number of rows&columns for matrix B: \n");
    scanf("%d %d",&row2,&column2);
    int a[row1][column1];
    int b[row2][column2];
    int m[row1][column2];
    memset(m,0,sizeof(m)); //一定要初始化

    printf("elements of matrix A: \n");
    InputMatrix(row1,column1,(int **)a);
    printf("elements of matrix B: \n");
    InputMatrix(row2,column2,(int **)b);

    for(i=0;i<row1;i++){
        for(j=0;j<column2;j++){
            for (k=0;k<column1;k++){
                m[i][j]+=*(*(a+i)+k)+*(*(b+k)+j);
            }
        }
    }
    DispMatrix(row1,column2,(int**)m);
    return 0;
}
void InputMatrix(int rows, int columns, int **a){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",(int*)a+i*columns+j);
        }
    }
    return;
}
void DispMatrix(int rows, int columns,int **a){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d ",*((int*)a+i*columns+j));
        }
    printf("\n");
    }
}