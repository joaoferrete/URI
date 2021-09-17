#include <stdio.h>

int main() {
    int par[5], impar[5], i, a, b=0, c=0, d;
    for(i=0; i<15; i++){
        scanf("%d", &a);
        if(a%2==0){
            par[b]=a;
            b++;
        }else{
            impar[c]=a;
            c++;
        }
        if(b>=5){
            for(d=0; d<5; d++){
                printf("par[%d] = %d\n", d, par[d]);
            }
            b=0;
        }
        if(c>=5){
            for(d=0; d<5; d++){
                printf("impar[%d] = %d\n", d, impar[d]);
            }
            c=0;
        }
    }
    if(c!=0){
        for (i=0; i<c; i++){
            printf("impar[%d] = %d\n", i, impar[i]);
        }
    }
    if(b!=0){
        for (i=0; i<b; i++){
            printf("par[%d] = %d\n", i, par[i]);
        }
    }
    return 0;
}