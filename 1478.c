#include <stdio.h>
#include <stdlib.h>

int main (){
    int mat[100][100], x, i, j, a=1;
    while(1){
        scanf("%d", &x);
        if(x==0){
            break;
        }
        for (i=0; i<x; i++){
            for(j=0; j<x; j++){
                if(i<j){
                    mat[i][j] = a;
                    a = a+1;
                }else{
                    mat[i][j] = abs(i+1-j);
                }
                if(j < (x-1)){
                    printf("%3d ", mat[i][j]);
                }else{
                    printf("%3d\n", mat[i][j]);
                }
            }
            a = 2;
        }
        a = 2;
        printf("\n");
    }
    return 0;
}