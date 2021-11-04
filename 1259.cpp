#include <bits/stdc++.h>
using namespace std;

bool ordena(unsigned long a, unsigned long b) {
    if(a%2 == 0 && b%2 == 0) return a < b;
    if(a%2 == 1 && b%2 == 1) return a > b;
    return a%2 == 0;
}

int main(){
   vector < unsigned long > v;
    unsigned long n;
    cin >> n;

    for(unsigned long i = 0; i < n; i++){
        unsigned long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), ordena);
    for(unsigned long i = 0; i < n; i++) cout << v[i] << endl;
}