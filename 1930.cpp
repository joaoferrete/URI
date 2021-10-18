#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int n ;
    cin >> n;
    v.push_back(n);
    cin >> n;
    v.push_back(n);
    cin >> n;
    v.push_back(n);
    cin >> n;
    v.push_back(n);

    sort(v.begin(), v.end());
    cout << v[0]-1 + v[1]-1 + v[2]-1 + v[3] << endl;
}