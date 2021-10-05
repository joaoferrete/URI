#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull c, n, p, q;
    string carac;
    vector <ull> vet(1001);
    
    while(cin >> c >> n){
        ull fatura = 0;
        vet.assign(1001, 0);

        for(ull i=0; i< n; i++){
            cin >> carac;
            if(carac == "C"){
                cin >> p >> q;
                ull cont = 0;
                bool paga = false;
                for(ull j = 0; j< c; j++){
                    //cout<<j<<endl;
                    if(vet[j]==0) cont++;
                    else cont = 0;
                    if (cont == q){
                        //cout<<cont <<" "<< j <<endl;
                        for(ull k=j-cont+1; k<=j; k++){
                            vet[k] = p;
                            paga = true;
                        }
                        break;
                    }
                    
                }
                if(paga) fatura ++;
            }
            else{
                cin >> p;
                bool flag = false;
                for(ull j=0; j< c; j++){
                    if(vet[j]==p){
                        vet[j] = 0;
                        flag = true;
                    }
                    else if (vet[j]!=0 && flag){
                        break;
                    }
                }
            }
            /*for(ull j=0; j< c; j++){
                cout << vet[j] << " ";
            }
            cout << endl;*/
        }
        cout<< fatura*10 << endl;
    }
}

