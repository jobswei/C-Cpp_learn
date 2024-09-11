#include<stdio.h>
#include<math.h>
int main(){
    int N,a[1001][3],i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    int m,n,count=0;
    for(m=0;m<N;m++){
        for(n=m+1;n<N;n++){
            int k,flag=1,sum1=0,sum2=0;
            for(k=0;k<3;k++){
                if(abs(a[n][k]-a[m][k])>5) {
                    flag=0;
                    break;
                }
                sum1+=a[n][k];
                sum2+=a[m][k];
            }

			if((abs(sum1-sum2)<=10)&&(flag==1)) count++; 
        }
    }
    printf("%d",count);
	return 0; 
}
