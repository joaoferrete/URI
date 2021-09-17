#include <stdio.h>

int main() {
    int i, j;
    long long int saques[100], saques1[100], bloqueios[100], bloqueios1[100], ataques[100], ataques1[100];
    double a=0, a1=0, b=0, b1=0, s=0, s1=0;
    char nome[100];
    scanf("%d", &j);
    for(i=0; i<j; i++){
        scanf("%s", nome);
        scanf("%lld%lld%lld", &(saques[i]), &(bloqueios[i]), &(ataques[i]));
        scanf("%lld%lld%lld", &(saques1[i]), &(bloqueios1[i]), &(ataques1[i]));
    }
    for(i=0; i<j; i++){
        s=s+saques[i];
        s1=s1+saques1[i];
        b=b+bloqueios[i];
        b1=b1+bloqueios1[i];
        a=a+ataques[i];
        a1=a1+ataques1[i];
    }
    printf("Pontos de Saque: %.02lf %%.\n", (s1/s)*100);
    printf("Pontos de Bloqueio: %.02lf %%.\n", (b1/b)*100);
    printf("Pontos de Ataque: %.02lf %%.\n", (a1/a)*100);
    return 0;
}