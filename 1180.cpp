#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    vector <int> vet;

    cin >> n;

    int menor=5000, pos = 0;
    for(int i = 0; i < n; i++){
        cin >> m;
        vet.push_back(m);
    }

    for(int i = 0; i < n; i++){
        if(vet[i] < menor){
            menor = vet[i];
            pos = i;
        }
    }

    cout<<"Menor valor: " << menor << endl;
    cout<<"Posicao: " << pos << endl;
    
}