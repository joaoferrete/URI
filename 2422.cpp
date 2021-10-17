#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n;
    cin >> n;
    vector <llu> v(n);

    for(llu i = 0; i < n; ++i) cin >> v[i];

    llu k;
    cin >> k;

    for(llu i = 0; i < n/2 +1; ++i){
        llu x = k - v[i];
        bool find = binary_search(v.begin()+i, v.end(), x);
        if(find){
            cout << v[i] << " " << x << endl;
            return 0;
        }
    }
    
}