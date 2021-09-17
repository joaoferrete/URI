#include <bits/stdc++.h>
using namespace std;

int main(){
    long m, n, c, i, j=0, k, v[51];
    cin>>c>>n;
    if(c%2==0 && n%2==0) cout<<"1"<<endl;
    else if (c%2==0 && n%2==1) cout<<"0"<<endl;
    else if (c%2==1 && n%2==0) cout<<"0"<<endl;
    else if (c%2==1 && n%2==1) cout<<"1"<<endl;
}
