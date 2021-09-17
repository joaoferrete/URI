#include <stdio.h>

int main(){
    int a, i, vet[10];
    scanf("%d", &a);
    vet[0]=a;
    for(i=1; i<10; i++){
        vet[i]=2*vet[i-1];
    }
    for(i=0; i<10; i++){
        printf("N[%d] = %d\n", i, vet[i]);
    }
    return 0;
}