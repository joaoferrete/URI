#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m;

bool ordena(ll a, ll b) {
    if(a % m == b % m){
        if(abs(a % 2) == 0 && abs(b % 2) == 0) return a < b;
        if(abs(a % 2) == 1 && abs(b % 2) == 1) return a > b;
        if(abs(a % 2) == 0 && abs(b % 2) == 1) return false;
        if(abs(a % 2) == 1 && abs(b % 2) == 0) return true;
    }
    return (a % m) < (b % m);
}

int main(){
    ll n;

    while(true){
        cin >> n >> m;
        cout << n << " " << m << endl;
        if(n == 0 && m == 0) break;

        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), ordena);

        for(ll i = 0; i < n; i++) cout << v[i] << endl;

    }
    return 0;
}