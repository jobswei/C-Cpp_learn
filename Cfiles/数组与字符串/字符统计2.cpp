#include<stdio.h>
#include<ctype.h>
#define NUM 26
int main(){
	int c,upper=0,total=0,lower[NUM]={0};
	while((c=getchar())!='*'){
		if(islower(c)){
			lower[c-'a']++;
		}
		else if(isupper(c)){
			upper++;
		total++;		
		}
	}
	for(int i=0;i<NUM;i++){
		if(lower[i]!=0) printf("%c:%d\n",i+'a',lower[i]);
	}
	printf("Upper:%d\nTotal:%d\n",upper,total);
	return 0;
}
