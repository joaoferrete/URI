#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu h1, m1, h2, m2, min=0;

    while(true){
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        if(h1>h2 || (h1==h2 && m1>m2)) h2+=24;

        min = (h2-h1)*60 + m2-m1;
        cout << min << endl;
    }

}