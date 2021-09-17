#include <stdio.h>
#include <stdlib.h>

int main(){
    long long a, n, v, qt=0;
    scanf("%lld %lld", &a, &n);
    while(n--){
        scanf("%lld", &v);
        if(v*a>=40000000) qt++;
    }
    printf("%lld\n", qt);
    return 0;
}