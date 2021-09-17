#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, d, e, i;
    scanf("%d",&a);
    while(a!=0){
        scanf("%d%d",&b,&c);
        for(i=0;i<a;i++){
            scanf("%d%d",&d,&e);

            if((d==b || d==c) || (e==b || e==c)){
                printf("divisa\n");
            }else{
                if(d>b && e>c){
                    printf("NE\n");
                }else if(d>b &&e<c){
                    printf("SE\n");
                }else if(d<b && e>c){
                    printf("NO\n");
                }else{
                    printf("SO\n");
                }
            }
        }
        scanf("%d",&a);
    }
    return 0;
}