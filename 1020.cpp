#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout<<n/365<<" ano(s)"<<endl;
    n = n%365;
    cout<<n/30<<" mes(es)"<<endl;
    n = n%30;
    cout<< n <<" dia(s)"<<endl;
}