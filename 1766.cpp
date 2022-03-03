#include <bits/stdc++.h>
using namespace std;

struct rena{
    string nome;
    int peso;
    int idade;
    float altura;
};

bool ordena(rena a, rena b){
    if(a.peso == b.peso)
        if(a.idade == b.idade)
            if(a.altura == b.altura)
                return a.nome < b.nome;
            else
                return a.altura < b.altura;
        else
            return a.idade < b.idade;
    else
        return a.peso > b.peso;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m, k;
        cin >> m >> k;
        vector <rena> v(m);
        for(int j = 0; j < m; j++){
            cin >> v[j].nome >> v[j].peso >> v[j].idade >> v[j].altura;
        }
        sort(v.begin(), v.end(), ordena);

        cout << "CENARIO {" << i+1 << "}" << endl;
        for(int j = 0; j < k; j++){
            cout << j+1 << " - " << v[j].nome << endl;
        }
    }
}