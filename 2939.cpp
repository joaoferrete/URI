#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

#define MOD 1000000007

int main(){
    llu n, a = 2, b = 1, c = 0;
    cin >> n;

    for (llu i=2; i<=n; ++i){
        c = a;
        a = (2 * i * c) % MOD;
        a += (((4 * i * (i-1))%MOD) * b) % MOD;
        a %= MOD;
        b = c;
    }
    if(n == 1) cout << 2 << endl;
    else if(n == 2) cout << 16 << endl;
    else cout<< a <<endl;
}