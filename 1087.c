#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, x1, x2, y1, y2;
    while(1){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1==0 && x2==0 && y1==0 && y2==0){
            break;
        }
       else if(x1==x2 && y1==y2)
            printf("0\n");

       else if(x1==x2 || y1 == y2 || abs(x1-x2)==abs(y1-y2))
            printf("1\n");
       else{
            printf("2\n");
       }
        
    }
    return 0;    
}