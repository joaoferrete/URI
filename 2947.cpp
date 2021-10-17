#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maior(vector <ll> v){
    ll maior = 0;
    for(ll i = 1; i < 30; i++){
        if(v[i] > v[maior]) maior = i;
    }
    return maior;
}

int main(){
    ll k, n;
    cin >> k;
    string desarf;
    cin >> desarf;
    cin >> n;
    vector <string> v(n);
    vector <ll> v2(30);
    v2.assign(30, 0);
    string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    ll ans = 0;
    for(ll i = 0; i < k; ++i){
        for(ll j = 0; j < n; ++j){
            if (v[j][i] != desarf[i]){
                v2[A.find(v[j][i])]++;
            }
        }
        ans += v2[maior(v2)];
        v2.assign(30, 0);   
    }
    cout << ans << endl;
}