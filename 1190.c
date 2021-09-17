#include <stdio.h>

int main() {
    int i, j, d=0, f=11;
    float m[12][12], t=0;
    char s;
    scanf("%c",&s);
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            scanf("%f", &(m[i][j]));
        }
    }
    if (s=='S'){
        for(i=1;i<6; i++){
            for(j=0; j<i; j++){
                t = t + m[i][f-j];
            }
        }
        for(i=6; i<12; i++){
            for(j=11; j>i; j-- ){
                t=t+m[i][j];
            }
        }
        printf("%.1f\n", t);
    }else if(s=='M'){
        for(i=1;i<6; i++){
            for(j=0; j<i; j++){
                t = t + m[i][f-j];
                d+=1;
            }
        }
        for(i=6; i<12; i++){
            for(j=11; j>i; j-- ){
                t=t+m[i][j];
                d+=1;
            }
        }
        printf("%.1f\n", t/d);
    }
    return 0;
}
