#include <stdio.h>
#include <stdlib.h>

int main(){
    int c[70][70];
    int a,i,j,x=0,y;

    while(scanf("%d",&a)!=EOF){
        y = a-1;
        x=0;
        for(i=0;i<a;i++){
            for(j=0;j<a;j++){
                if((i==0)&&(j==0)){
                    c[i][j] = 1;
                    printf("%d",c[i][j]);
                }else if ((i==x)&&(j==y)){
                    c[i][j] = 2;
                    printf("%d",c[i][j]);
                }else{
                    if(j==i){
                        c[i][j] = 1;
                        printf("%d",c[i][j]);
                    }else{
                        c[i][j] = 3;
                        printf("%d",c[i][j]);
                    }
                }
            }
            printf("\n");
            x++;
            y--;
        }
    }
    return 0;
}
