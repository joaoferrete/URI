#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int a, b;
    cin >> a >> b;
    
    if (a > b) swap(a, b);

    for(unsigned int i = a+1; i < b; i++){
        if(i % 5 == 2 || i % 5 == 3){
            cout << i << endl;
        }
    }
}