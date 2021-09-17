#include <stdio.h>

int main() {
    int i, vet[20];
    for(i=0; i<20; i++){
        scanf("%d", &vet[i]);
    }
    for(i=0; i<20; i++){
        printf("N[%d] = %d\n", i, vet[19-i]);
    }
    return 0;
}
