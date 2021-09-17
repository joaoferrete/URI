#include <bits/stdc++.h>
using namespace std;

bool ehvdd(long v[], long n, long k){
    int i;
    for(i=0;i<n;i++){
        if(k==v[i]) return true;
    }
    return false;
}

int main(){
    long m, n, c, i, j=0, k, v[51];
    vector<long> v1 (100, 0);
    cin>>n>>c>>m;
    for(i=0;i<c;i++){
        cin>>v[i];
    }
    for(i=0;i<m;i++){
        cin>>k;
        v1[k-1]++;
    }
    for(i=0;i<n;i++){
        if(v1[i]==0 && ehvdd(v, c, i+1)==true) j++;
    }
    cout<<j<<endl;
}