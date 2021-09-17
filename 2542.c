#include <stdio.h>
#include <stdlib.h>

int main(){
    int vm[100][100],vl[100][100];
    int f,b,c,d,e,i,j,a;

    while(scanf("%d",&f)!=EOF){

        scanf("%d%d",&b,&c);
        for(i=0;i<b;i++){
            for(j=0;j<f;j++){
                scanf("%d",&vm[i][j]);
            }
        }
        for(i=0;i<c;i++){
            for(j=0;j<f;j++){
                scanf("%d",&vl[i][j]);
            }
        }
        scanf("%d%d",&d,&e);
        scanf("%d",&a);
        if(vm[d-1][a-1] > vl[e-1][a-1]){
            printf("Marcos\n");
        }else if(vm[d-1][a-1] < vl[e-1][a-1]){
            printf("Leonardo\n");
        }else{
            printf("Empate\n");
        }
    }

    return 0;
}
