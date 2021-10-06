#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n;
    vector <llu> v;
    
    while(true){
        cin >> n;
        if (n == 0) break;

        llu sum = 0;

        for(llu i = 0; i < n; i++){
            llu x;
            cin >> x;
            v.push_back(x);
        }
        llu cont = 0;

        if(v[0] == 0 && v[1] == 0 && v[2] == 0){
            sum++;
            v[1] = 1;
        }

        if(v[0] == 0 && v[1] == 0 && v[n-1] == 0){
            sum++;
            v[0] = 1;
        }
        
        if(v[0] == 0 && v[n-1] == 0 && v[n-2] == 0){
            sum++;
            v[n-1] = 1;
        }
        
        for(llu i = 0; i < n; i++){
            if(v[i]==0) cont++;
            
            if(cont == 2){
                sum += 1;
                cont = 0;
                v[i] = 1;
            }
            if(cont!=0 && v[i]==1) cont = 0;
        }
        if(v[n-1]==0 && v[0]==0) sum += 1;
        /*
        for(llu i = 0; i < n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;*/
        
        cout << sum << endl;
        v.clear();
    }
}