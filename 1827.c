#include <stdio.h>
#include <stdlib.h>


int main(){
	int i,j,a,b,c;
    int m[101][101];

	while(scanf("%d",&a)!=EOF){
		for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				if(i==j){
                    m[i][j]=2;
				}else if(i+j==a-1){
                    m[i][j]=3;
				}else{
                    m[i][j]=0;
                }
			}
        }
		b = a/3;
		c = a-b;
		for(i=b;i<c;i++)
			for(j=b;j<c;j++){
				 m[i][j] = 1;
			}
		m[a/2][a/2] = 4;
		for(i=0;i<a;i++){
			 for(j=0;j< a;j++){
				 printf("%d", m[i][j]);
             }
			 printf("\n");
		 }
		 printf("\n");

	}
	return 0;
}
