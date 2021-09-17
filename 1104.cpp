#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

llu minimo(llu a, llu b) {
    return a < b ? a : b;
}

int main() {
    llu a, b, n;
    set<llu> sa, sb;
    vector <llu> intersection, diference1, diference2;

    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        for(llu i = 0; i<a; i++){
            cin >> n;
            sa.insert(n);
        }
        for(llu i = 0; i<b; i++){
            cin >> n;
            sb.insert(n);
        }
        set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(intersection));
        set_difference(sa.begin(), sa.end(), intersection.begin(), intersection.end(), back_inserter(diference1));
        set_difference(sb.begin(), sb.end(), intersection.begin(), intersection.end(), back_inserter(diference2));
        cout << minimo(diference1.size(), diference2.size()) << endl;
        
        sa.clear();
        sb.clear();
        intersection.clear();
        diference1.clear();
        diference2.clear();

    }
}
