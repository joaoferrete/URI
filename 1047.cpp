#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    
    m1+=h1*60;
    m2+=h2*60;
    if (m1 >= m2) m2+=24*60;

    h1 = (m2-m1)/60;
    m1 = (m2-m1)%60;
    printf("O JOGO DUROU %llu HORA(S) E %lld MINUTO(S)\n", h1, m1);

}