#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, m, i, j=0, k;
    vector <int> v(100,0);
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>k;
        v[k-1]++;
    }
    for(i=0;i<n;i++){
        if(v[i]==0) j++;
    }
    cout<<j<<endl;
}
