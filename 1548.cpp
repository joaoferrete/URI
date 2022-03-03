#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector <int> v(m);
        vector <int> v2(m);
        for(int j = 0; j < m; j++){
            cin >> v[j];
        }
        v2 = v;
        sort(v.begin(), v.end(), greater<int>());
        int cont = 0;
        for(int j = 0; j < m; j++){
            //cout << v[j] << " " << v2[j] << endl;
            if(v[j] == v2[j]) cont++;
        }
        cout << cont << endl;
    }
}