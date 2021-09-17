#include <stdio.h>

int main() {
    int i, j, d;
    float m[12][12], t=0;
    char s;
    scanf("%d %c", &d, &s);
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            scanf("%f", &(m[i][j]));
        }
    }
    if (s=='S'){
        for(j=0; j<12; j++){
            t = t + m[d][j];
        }
        printf("%.1f\n", t);
    }else if(s=='M'){
        for(j=0; j<12; j++){
            t = t + m[d][j];
        }
        printf("%.1f\n", t/12);
    }
    return 0;
}
