#include<stdio.h>
#include<ctype.h>
char *get_value(char *s,double *d)
 int main(){
     int i,n;
     double d,sunsum;
     char buf[BUFSIZE],*p;

     for(i=1;fgets(buf,BUFSIZE,stdin)!=NULL;i++){
        subsum=0;
        for(n=0,p=buf;(p=get_value(p,&d))!=NULL;n++)
            subsum+=d;
        if(n>0)
            prinf("%d:%d %f\n",i,n,subsum/n);
    return 0;
     }
 }

 char *get_value(char *s,double *d){
     while(*s!='\0'&&isspace(*s)) s++;
     if(sscanf(s,"%lf",d)!=1) return NULL;
     while(*s!='\0'&& ! isspace(*s)) s++;
     return s;
 }