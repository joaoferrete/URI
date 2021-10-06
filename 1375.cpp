#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    vector <ll> v(10001);

    while(true){
        cin>>n;
        
        if (n == 0) break;

        v.assign(10001, 0);

        bool flag = false;

        for(ll i = 0; i < n; i++){
            ll x, y;
            cin>>x >> y;
            if (abs(y)>n || x<1){
                flag = true;
            }
            else if (v[i+y] == 0) v[i+y] = x;
            else{
                flag = true;
            }
        }

        bool a = (find(v.begin(), v.begin()+n, 0) != v.begin()+n);

        if(flag || a) cout << "-1" <<endl;
        else{
            for(ll i = 0; i < n; i++){
                if (i<n-1) cout << v[i] << " ";
                else cout << v[i] << endl;
            }
        }

    }
    return 0;
}