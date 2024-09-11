#include<stdio.h>
#include<string.h> 
#define N 128
int main(){
    // char str_a[N],str_b[N];
    // double v;
    // scanf("%s %s",str_a,str_b);
    // printf("%s %s\n",str_a[1],str_b);

    // char string[N];
    // if (gets(string)!= NULL) printf("%s\n",string);
    // if (fgets(string,3,stdin)!= NULL) printf("%s\n",string);

    char s[32];
//    strcpy(s,"This is a box");
//    puts(s);
    strncpy(s,"This is a boz",4);
    puts(s);
//    char c;
//    for(int i=0;(c=s[i]);i++)
//    	printf("%c",c);
//    printf("\n%c 1\n",'\0');

    char a[32]="Hellow";
	char b[32]="Good Morning";
	char c[]="World";
    strcat(a,c);
    strncat(b,c,6);
    puts(a);
    puts(b);

    printf("%d",strcmp(a,b));
    printf("%d",strncmp(a,c,3));

    printf("%d",strlen(a));
    
    // char *strchr(char *s,int c);
    // char *strrchr(char *s,int c);
    // char *strstr(char *s, char *s1);
    return 0;
}
