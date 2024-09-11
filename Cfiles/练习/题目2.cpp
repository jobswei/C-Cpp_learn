#include<stdio.h>
 int main(){
     int l,m,a[10002]={0},i,count=0;
     scanf("%d %d",&l,&m);
     for(i=0;i<m;i++){
         int c,d,j;
         scanf("%d %d",&c,&d);
         for(j=c-1;j<d;j++){
             a[j]=1;
         }
     }
     for(i=0;i<=l;i++){
         if(a[i]==0) count++;
     }
     printf("%d",count);
     return 0;
 }
