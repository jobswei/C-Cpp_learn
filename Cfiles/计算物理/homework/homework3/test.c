#include<stdio.h>
#include"selfRand.h"

int main(){
    for(int i=0;i<100;i++){
    int y=MSRand();
    printf("%d\n",y);
    }
}