#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(){
    ll n, l;
    vector <string> s;
    cin >> n;

    while(n--){
        cin >> l;
        for (ll i=0; i < l; i++){
            string temp;
            cin >> temp;
            s.push_back(temp);
        }
        ll ans = 0;
        for (ll i=0; i < l; i++){
            for (ll j=0; j < s[i].size(); j++){
                ans+=alfa.find(s[i][j]) + i + j;
            }
        }
        cout << ans << endl;
        s.clear();
    }
}