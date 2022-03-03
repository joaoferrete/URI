#include <bits/stdc++.h>
using namespace std;

struct medalhas{
    int a, b, c;

};

bool compara(pair<string, medalhas> a, pair<string, medalhas> b){
    if(a.second.a == b.second.a)
        if(a.second.b == b.second.b)
            if(a.second.c == b.second.c)
                return a.first < b.first;
            else
                return a.second.c > b.second.c;
        else
            return a.second.b > b.second.b;
    else
        return a.second.a > b.second.a;
}

int main(){
    string s;
    map<string, medalhas> m;

    while(getline(cin, s)){
        getline(cin, s);
        if(m.find(s) == m.end()){
            medalhas aux;
            aux.a = 1;
            aux.b = 0;
            aux.c = 0;
            m[s] = aux;
        }
        else{
            m[s].a++;
        }
        getline(cin, s);
        if(m.find(s) == m.end()){
            medalhas aux;
            aux.a = 0;
            aux.b = 1;
            aux.c = 0;
            m[s] = aux;
        }
        else{
            m[s].b++;
        }
        getline(cin, s);
        if(m.find(s) == m.end()){
            medalhas aux;
            aux.a = 0;
            aux.b = 0;
            aux.c = 1;
            m[s] = aux;
        }
        else{
            m[s].c++;
        }
    }

    //sort(m.begin(), m.end());
    vector<pair<string, medalhas>> v;
    
    for(auto it = m.begin(); it != m.end(); it++){
        v.push_back(make_pair(it->first, it->second));
    }
    sort(v.begin(), v.end(), compara);

    cout<<"Quadro de Medalhas"<<endl;
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<it->first<<" "<<it->second.a<<" "<<it->second.b<<" "<<it->second.c<<endl;
    }
}