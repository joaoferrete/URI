#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,s;
    long int m[10005];
    scanf("%d",&n);
    while(n!=0){
        s=0;
        for(i=0;i<n;i++){
            scanf("%ld",&m[i]);
        }
        for(i=0;i<n;i++){
            if(m[i]<m[(i+1)%n]){
                if(m[(i+1)%n]>m[(i+2)%n]){
                    s++;
                }
            }
            if(m[i]>m[(i+1)%n]){
                if(m[(i+1)%n]<m[(i+2)%n]){
                    s++;
                }
            }
        }
        printf("%d\n",s);
        scanf("%d",&n);
    }
    return 0;
}