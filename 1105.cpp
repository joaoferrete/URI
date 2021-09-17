#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll b, n;
    vector<ll> bancos;


    while(true){
        cin >> b >> n;
        if(b == 0 && n == 0) break;
        for(ll i = 0; i < b; i++){
            ll x;
            cin >> x;
            bancos.push_back(x);
        }
        for(ll i = 0; i < n; i++){
            ll d, c, v;
            cin >> d >> c >> v;
            bancos[d-1] -= v;
            bancos[c-1] += v;
        }
        bool ok = true;
        for(ll i = 0; i < b; i++){
            if(bancos[i] < 0) ok = false;
        }
        if(ok) cout << "S\n";
        else cout << "N\n";
        bancos.clear();
    }
}