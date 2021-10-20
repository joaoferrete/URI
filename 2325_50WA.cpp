#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu c, n;
    map <llu, llu> m;
    map <llu, llu> map2;

    cin >> c >> n;

    for(llu i = 0; i < c; i++){
        llu a, b;
        cin >> a >> b;
        m.insert({a, b});
    }
    for(llu i = 0; i < n; i++){
        llu a, b;
        cin >> a >> b;
        map <llu, llu>::iterator it = map2.find(a);
        if(it != map2.end()){
            if(it->second < b) it->second = b;
        }
        else{
            it = m.find(a);
            if(it->second < b) map2.insert({a, b});
        }
    }

    for(map <llu, llu>::iterator it = map2.begin(); it != map2.end(); it++){
        cout << it->first << " " << it->second << endl;
    }


}