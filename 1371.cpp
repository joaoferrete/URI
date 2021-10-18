#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n;
    cin >> n;
    vector<llu> seq;
    for(llu i=0; i < 5001; i++){
        seq.push_back(pow(i, 2));
    }

    while(n!=0){
        n = sqrt(n);
        for(llu i=1; i<=n; ++i){
            if(i<n) cout << seq[i] << " "; 
            else cout << seq[i] << endl;
        }
        cin >> n;
    }
}