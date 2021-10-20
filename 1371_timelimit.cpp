#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n;
    vector <bool> portas(25000001, true);

    cin >> n;
    while(n!=0){
        for(llu i=2; i<=n; ++i){
            for(llu j=i; j<=n; j+=i){
                portas[j] = !portas[j];
            }
        }
        for(llu i=1; i<=n; ++i){
            if(portas[i]){
                if (i==1) cout << i;
                else cout << " " << i;
            }
        }
        cout << endl;
        cin >> n;
        portas.assign(n+1, true);
    }

}