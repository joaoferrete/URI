#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool compara(map <string, int>::iterator a, map <string, int>::iterator b)
{
    return a->second > b->second;
}


int main(){
    ll n;
    cin >> n;

    map <string, int> arv;

    bool primeiro = true;

    while(n--){
        if(primeiro){
            primeiro = false;
            string a;
            getline(cin, a);
            getchar();
        }

        string nome;
        ll qt = 0;
        while(getline(cin, nome)){
            if(nome.size() == 0) break;
            ++qt;
            map <string, int>::iterator it = arv.find(nome);
            if(it == arv.end()){
                arv.insert(make_pair(nome, 1));
            }else{
                it->second += 1;
            }
            
        }
        
        for(map <string, int>::iterator i= arv.begin(); i!=arv.end(); ++i){
            cout << i->first;
            printf(" %.4f\n", (double)i->second/qt*100);
        }
        arv.clear();
        if(n!=0) cout<<endl;


    }

}