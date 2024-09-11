#include<stdio.h>

void str_rev(char s[]);
int main(){
    char a[101];
    gets(a);
    str_rev(a);
    puts(a);
    return 0;
}

void str_rev(char s[]){
    int lo=0,hi=0,t;
    while (s[hi] != '\0') hi++;
    for (hi--;hi>lo;lo++,hi--){
        t=s[lo];
        s[lo]=s[hi];
        s[hi] = t;
    }
}
