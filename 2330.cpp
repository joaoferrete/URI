#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, l;
    cin >> n >> l;
    vector<long long> vendedor(n);
    vector <long long> chamadas(n);
    queue <long long> ligacoes;
    for(long long i=0; i<l; i++){
        long long a;
        cin >> a;
        ligacoes.push(a);
    }
    bool flag = true;
    while(!ligacoes.empty()){
        if(flag){
            for(long long i=0; i<n; i++){
                if(ligacoes.empty()) break;
                vendedor[i] = ligacoes.front();
                ligacoes.pop();
                chamadas[i]++;
            }
            flag = false;
        }
        else{
           
            for(long long i=0; ; i++){
                if(i==n) i=0;
                if(ligacoes.empty()) break;
                
                if (vendedor[i]!=0){
                    vendedor[i]--;
                }
                if(vendedor[i] == 0){
                    vendedor[i] = ligacoes.front();
                    chamadas[i]++;
                    ligacoes.pop();
                }

            }
        }
    }
    for(long long i=0; i<n; i++){
        cout <<i+1<<" "<< chamadas[i] <<endl;
    }
}