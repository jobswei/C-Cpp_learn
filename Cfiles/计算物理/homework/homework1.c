#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdarg.h>
#include<malloc.h>
#define N 2

void bubble_sort(double arr[], int *nums, int n) {
    // 从大到小排列
    int i, j, num;
    double temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                num=*(nums+j);
                *(nums+j)=*(nums+j+1);
                *(nums+j+1)=num;
            }
        }
    }
}
void dealScore(double *arr,int n){
    // 对分数进行开根号与乘以10
    for(int i=0;i<n;i++){
        *(arr+i)=sqrt(*(arr+i))*10;
    }
}
double *getAveScore(int length,int n,...){
    // 求平均成绩
    // 传入未定变量，可以求多门成绩的平均分
    static double *averScore;
    averScore = (double *)malloc(sizeof(double)*length);
    // 初始化
    for(int j;j<length;j++){
        *(averScore+j)=0;
    }
    //求平均
    va_list argptr;
    va_start(argptr,n);
    for(int i=0;i<n;i++){    
        double *d=va_arg(argptr, double*);
        for(int j=0;j<length;j++){
            *(averScore+j)+=*(d+j)/n;
        }
    }
    va_end(argptr);
    return averScore;
}

int main(){
    int nums[N+1]; // 这个数组是为了在冒泡排序时同步更新，以确定输出顺序
    char ids[N+1][64];
    double CalPhyScore[N+1];
    double EngScore[N+1];
    double *AverScore;
    
    // 读取
    for(int count=0;count<N;count++){
        printf("Input id: \n");
        scanf("%s",*(ids+count));
        printf("Input CalPhy score,English score: \n");
        scanf("%lf,%lf",CalPhyScore+count,EngScore+count);
        *(nums+count)=count;   
    }
    // 处理
    dealScore(CalPhyScore,N);
    dealScore(EngScore,N); 
    AverScore=getAveScore(N,2,CalPhyScore,EngScore);
    bubble_sort(AverScore,nums,N);
    // 输出
    char state[][10]={"pass","not pass"};
    for(int count=0;count<N;count++){
        printf("classmate: %s---",*(ids+count));
        printf("Physics: %s, English: %s\n",(*(CalPhyScore+count)<60)?*(state+1):*state,(*(EngScore+count)<60)?*(state+1):*state);
    }
    for(int count=0;count<N;count++){
        int num=*(nums+count);
        printf("classmate: %s---Average Score: %.2f\n",*(ids+num),*(AverScore+count));
    }
    system("pause");
    return 0;
}