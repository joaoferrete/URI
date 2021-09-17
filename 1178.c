#include <stdio.h>

int main() {
    double vet[100], x;
    int i;
    scanf("%lf", &x);
    vet[0]=x;
    for(i=1; i<100; i++){
        vet[i]=(vet[i-1]/2);
    }
    for (i=0; i<100; i++){
        printf("N[%d] = %0.4lf\n", i, vet[i]);
    }
    return 0;
}