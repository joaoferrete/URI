#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu p, c, n;
    vector <llu> v;

    cin >> p >> c >> n;

    for(llu i = 0; i < n; i++){
        llu x;
        cin >> x;
        v.push_back(x);
    }

    llu peso = p+c;
    llu conta = 0;

     if (peso > v[0]) 
            peso = v[0];

    for(llu i = 1; i < n && peso > p ; ++i){
        if (peso > v[i] && v[i] >= p) {
            peso = v[i];
            conta++;
        }
    }
    cout << conta << endl;
}