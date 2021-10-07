#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;

    while(true){
        cin >> n;
        if (n==0) break;
        ll maior = n;
        while(n!=1){
            if (n%2 == 0) n = n/2;
            else n = n*3 + 1;
            if (n>maior) maior = n;
        }
        cout << maior << endl;

    }
}