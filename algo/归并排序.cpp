#include<iostream>
#include<vector>
#define maxn 100
using namespace std;

// 合并分别排序好的两个数组
void merge(int (&A) [],int l1,int r1,int l2,int r2){
    int * p1=A+l1, * p2=A+l2;
    int * temp;
    temp=new int[r2-l1+1];
    int i=0;
    while(p1-A<=r1&&p2-A<=r2){
        if(*p1<*p2){
            *(temp+i)=*p1;
        }else{
            *(temp+i)=*p2;
        }
        i++;
        p1++;
        p2++;
    }
    while(p1-A<=r1){
        *(temp+(i++))=*p1;
        p1++;
    }
    while(p2-A<=r2){
        *(temp+(i++))=*(p2);
        p2++;
    }
    int it=0;
    for(int i=l1;i<=r1;i++){
        A[i]=*(temp+(it++));
    }
    for(int i=l2;i<=r2;i++){
        A[i]=*(temp+(it++));
    }
    return ;
}
void mergeSort(int (&A)[], int left, int right){
    int mid=(left+right)/2;
    if(left<right){
        mergeSort(A,left,mid);  //先将左右区间分别归并排序
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right); // 再将左右区间合并
    }
    
}
// 一开始自己想的方法，只想到了分块，没有想到分成的两块还得结合起来。
int main(){
    int *p;
    int a=3;
    p=&a;
    cout<<*p<<endl;

    merge(p);
    cout<<*p<<endl;
    return 0;
}