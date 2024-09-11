#include<stdio.h>

int main(){
    int N,a[40005],i=0,decree=0,m;
    scanf("%d",&N);
    while(1){
    	if(getchar()=='\n') break;
        scanf("%d",&m);
        
		m+=i;
        if(decree%2==0){
            for(;i<m;i++){
            a[i]=0;
        }
        }
        else{
            for(;i<m;i++){
            a[i]=1;
        }
        }
        decree++;
    }
    i=0; 
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            printf("%d",a[i]);
            i++;
        }
        printf("\n");
    }

    return 0;
}
