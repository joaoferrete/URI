#include <stdio.h>

int main() {
    int i, a, b, vet[1000];
    scanf("%d", &a);
    for(i=0; i<1000; i++){
        b=0;
        do{
            if (i>999){
                break;
            }else{
                vet[i]=b;
                printf("N[%d] = %d\n", i, vet[i]);
                b++;
                i++;
            }
        }while (b<a);
        i--;
    }
    return 0;
}