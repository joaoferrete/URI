#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long a, b, x, s=0, a1=1, a2, a3, vet[101], i, j, v[101];
    cin>>a;
    cin>>b;
    for(j=0;j<a;j++){
        s=0;
        for(i=0;i<b; i++){
            cin>>x;
            s+=x;
            if(i==b-1) vet[j]=s;
        }
    }
    for(i=0;i<a;i++){
        v[i]=vet[i];
    }
    sort(v, v+a);
    for(i=0;i<a;i++){
        if(vet[i]==v[0]){
            cout<<i+1<<"\n";
            break;
        }
    }
    for(i=0;i<a;i++){
        if(vet[i]==v[1]){
            cout<<i+1<<"\n";
            break;
        }
    }
    for(i=0;i<a;i++){
        if(vet[i]==v[2]){
             cout<<i+1<<"\n";
             break;
        }
    }
    return 0;
}