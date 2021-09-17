#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(){
    long long int a, m, n, r;
    cin>>a;
    while(a--){
        cin>>m>>n;
        r = (long long int) (n*log10(m))+1;
        cout<<r<<"\n";
    }
    return 0;
}