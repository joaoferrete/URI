#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n, k;
    cin >> n;

    vector<llu> v(n);

    for(llu i = 0; i < n; i++){
        cin >> v[i];
    }

    cin >> k;

    llu i=0, j=n-1;
    while(i < j){
        if(v[i] + v[j] == k){
            cout << v[i] << " " << v[j] << endl;
            return 0;
        }
        else if(v[i] + v[j] < k){
            i++;
        }
        else{
            j--;
        }
    }

}