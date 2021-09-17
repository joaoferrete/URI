#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll n;
    vector<ll> numeros;
    vector <string> nomes;

    while(true){
        cin >> n;
        if(n == 0) break;
        for (ll i = 0; i < n; i++) {
            string nome;
            cin >> nome;
            nomes.push_back(nome);
            
            ll num;
            cin >> num;
            numeros.push_back(num);
        }
        ll num = numeros[0]+1;

        while(numeros.size() > 1){
            ll dif = numeros.size() - num;

            num = num % 2 == 0 ? num % numeros.size() : abs(dif) % numeros.size();

            ll salva = numeros[num];

            numeros.erase(numeros.begin()+num);
            nomes.erase(nomes.begin()+num);
            num = salva;
        }
        printf("Vencedor(a): ");
        cout << nomes[0] << endl;
        
        
        numeros.clear();
        nomes.clear();
    }

}