#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n;
    vector <llu> dir(62, 0);
    vector <llu> esq(62, 0);

    while(cin >> n){
        while(n--){
            llu num;
            string pe;
            cin >> num >> pe;
            if(pe == "D"){
                dir[num]++;
            }else{
                esq[num]++;
            }
        }
        llu cont = 0;
        for(int i = 30; i < 61; ++i){
            if(dir[i] > 0 && esq[i] > 0)
                cont += min(dir[i], esq[i]);
        }
        cout << cont << endl;
        dir.assign(62, 0);
        esq.assign(62, 0);
    }
}