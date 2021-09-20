#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct pessoa{
    string nome;
    ll numero;
    ll anterior;
    ll proximo;
} pessoa;

int main(){
    ll n;
    vector<pessoa> pessoas;

    while(true){
        cin >> n;
        if(n == 0) break;
        for (ll i = 0; i < n; i++) {
            pessoa p;
            cin >> p.nome >> p.numero;
            if(i == 0) p.anterior = n-1;
            else p.anterior = i-1;
            if(i == n-1) p.proximo = 0;
            else p.proximo = i+1;
            pessoas.push_back(p);
        }
        ll num = pessoas[0].numero;
        ll atual=0;

        while(n > 1){

            if(num % 2 != 0){
                //cout<<"HORARIO" <<endl;
                for(ll i = 0; i < num; i++){
                    atual = pessoas[atual].proximo;
                }
            }   
            else{
                //cout<<"ANTI-HORARIO" <<endl;
                for(ll i = 0; i < num; i++){
                    atual = pessoas[atual].anterior;
                }
            }
            num = pessoas[atual].numero;
            //cout<<"atual: "<<pessoas[atual].nome<<endl;
            pessoas[pessoas[atual].anterior].proximo = pessoas[atual].proximo;
            pessoas[pessoas[atual].proximo].anterior = pessoas[atual].anterior;
            //pessoas.erase(pessoas.begin()+atual);
            //atual = num%2 == 0 ? pessoas[atual].proximo : pessoas[atual].anterior;
            n--;

        }
        printf("Vencedor(a): ");
        cout << pessoas[pessoas[atual].proximo].nome << endl;
        
        pessoas.clear();
    }

}