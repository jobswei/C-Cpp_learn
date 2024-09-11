#include<stdio.h>
#include<math.h>
#ifndef SELFRANDOM_H
#define SELFRANDOM_H
void srand(unsigned int);
int LCRand();
int MSRand();
#endif


unsigned int seed=1234;
int LC_MAX=32768;

// Linear Congruential Method
int LCRand(void)
{
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed/65536) % 32768;
}

/* 设置随机数种子 */
void srand(unsigned int new_seed)
{
    seed = new_seed;
}

// mid-square method
// 即使做了很多修正，这种方法生成的随机数仍然会收敛到同一个。所以本次作业使用LCRand方法
int getLen(int seed){
    int len=0;
    while(seed!=0){
        len++;
        seed/=10;
    }
    return len;
}

int absoluteDigit=4;
int MSRand() {
    int digits = getLen(seed); // 记录种子的位数
    unsigned int square;
    int digit[2*absoluteDigit+1];
    
    // 保证digits为至少4位，而且取最大的位数，否则会收敛到同一个数
    if(absoluteDigit<digits){
        absoluteDigit=digits;
    }else{
        digits=absoluteDigit;
    }
    square = seed * seed; // 计算平方

    // 统计square的长度，如果不够seed的二倍，就在前面加0
    // 如果没有加0，那么随机数会越来越短，直至收敛到一个数
    // 不信可以试试[doge]
    int len=0;
    while(square>0){
        digit[len++]=square%10;
        square/=10;
    }
    if(len<digits*2){
        for(int i=len;i<digits*2;i++){
            digit[i]=0;
        }
        len=digits*2;
    }

    seed=0;
    for(int i=digits/2;i<3*digits/2;i++){
        seed+=digit[i]*pow(10,i-digits/2);
    }
    return seed; // 返回中间值作为随机数
}

