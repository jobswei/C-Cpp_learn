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

/* ������������� */
void srand(unsigned int new_seed)
{
    seed = new_seed;
}

// mid-square method
// ��ʹ���˺ܶ����������ַ������ɵ��������Ȼ��������ͬһ�������Ա�����ҵʹ��LCRand����
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
    int digits = getLen(seed); // ��¼���ӵ�λ��
    unsigned int square;
    int digit[2*absoluteDigit+1];
    
    // ��֤digitsΪ����4λ������ȡ����λ���������������ͬһ����
    if(absoluteDigit<digits){
        absoluteDigit=digits;
    }else{
        digits=absoluteDigit;
    }
    square = seed * seed; // ����ƽ��

    // ͳ��square�ĳ��ȣ��������seed�Ķ���������ǰ���0
    // ���û�м�0����ô�������Խ��Խ�̣�ֱ��������һ����
    // ���ſ�������[doge]
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
    return seed; // �����м�ֵ��Ϊ�����
}

