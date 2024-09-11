#include<stdio.h>
#define len(x) int(sizeof(x)/sizeof(x[0]))
int main(){
	double a[10];
	printf("%d,%d\n",sizeof(a),len(a));
	for (int i=0;i<len(a);i++){
		printf("%d",i);
	}
	return 0;
}
