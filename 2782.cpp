#include <bits/stdc++.h>
using namespace std;

int main(){
    long long m, n, i, j=1, k;
    vector<long long> v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    k=v[1]-v[0];
    for(i=1;i<n-1;i++){
        if(v[i+1]-v[i]!=k){
            k=v[i+1]-v[i];
            j++;
        }
    }
    if(n==1 || n==2) j=1;
    cout<<j<<endl;

}