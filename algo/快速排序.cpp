#include<iostream>

using namespace std;

int fast(int *& A , int begin, int end){
    int a=*(A+begin);
    int i=begin+1,j=end;
    while(i<j){
        if(*(A+i)>a && *(A+j)<a){
            int k=*(A+i);
            *(A+i)=*(A+j);
            *(A+j)=k;
            i++;j--;
        }else if(*(A+i)<=a){
            i++;
        }else{
            j--;
        }
    }
    int k=*(A+begin);
    *(A+begin)=*(A+i);
    *(A+i)=k;
    return i;
}
void fastSort(int *& A,int left,int right){
    int i=0;
    int mid=fast(A,left,right);
    fastSort(A,left,mid-1);
    fastSort(A,mid+1,right);

}