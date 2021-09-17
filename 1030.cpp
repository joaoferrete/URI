#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu nc, n, k;
    vector <llu> v;
    cin >> nc;
    for(llu l = 0; l < nc; l++){
        cin >> n >> k;
        for(llu i = 0; i < n; i++){
            v.push_back(i+1);
        }
        llu i = 0;
        while(v.size()>1){
            i = (i+k-1)%v.size();
            v.erase(v.begin()+i);
        }
        printf("Case %llu: %llu\n", l+1, v[0]);
        v.clear();
    }
}