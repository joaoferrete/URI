#include <bits/stdc++.h>
using namespace std;


typedef struct letra{
    int letra;
    int freq;
}letra;

bool compara(letra a, letra b){
    if (a.freq == b.freq)
        return a.letra > b.letra;
    return a.freq < b.freq;
}

int main(){
    string s;

    vector <letra> v;

    bool primeiro = false;
    while(getline(cin, s)){
        
        if(primeiro) cout<<endl;
        primeiro = true;

        for (int i=0; i < s.size(); ++i){
            bool existe = false;
            
            for (int j=0; j < v.size(); ++j){
                if (v[j].letra == int(s[i])){
                    ++v[j].freq;
                    existe = true;
                    break;
                }
            }
            if (!existe){
                letra l;
                l.letra = int(s[i]);
                l.freq = 1;
                v.push_back(l);
            }
        }

        sort(v.begin(), v.end(), compara);

        for (int i=0; i < v.size(); ++i){
            cout << v[i].letra << " " << v[i].freq << endl;
        }
        v.clear();
    }
}