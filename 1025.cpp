#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n, q, it = 0;
    vector <llu> marmores;

    
    while(true){
        it++;
        cin >> n >> q;
        if (n == 0 && q == 0) break;
        
        printf("CASE# %llu:\n", it);

        for(llu i=0; i<n; i++){
            llu temp;
            cin >> temp;
            marmores.push_back(temp);
        }
        
        sort(marmores.begin(), marmores.end());
        
        for(llu i=0; i<q; i++){
            llu temp;
            cin >> temp;
            llu pos = find(marmores.begin(), marmores.end(), temp) - marmores.begin();

            if (pos >= n) printf("%llu not found\n", temp);
            else printf("%llu found at %llu\n", temp, pos+1);
        }
        marmores.clear();
    }

}