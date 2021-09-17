#include <stdio.h>

int main(){
    int a, i, vet[10];
    for(i=0; i<10; i++){
        scanf("%d", &a);
        if (a<1){
            vet[i]=1;
        }else{
            vet[i]=a;
        }
    }
    for(i=0; i<10; i++){
        printf("X[%d] = %d\n",i, vet[i]);
    }
    return 0;
}