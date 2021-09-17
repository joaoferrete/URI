#include <bits/stdc++.h>
using namespace std;

bool isPrime(unsigned long long n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (unsigned long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    unsigned long long n, conta=0, m=0;
    vector <unsigned long long> v;

    v.push_back(2);    
    for (unsigned long long i = 3; conta<= 3502; i+=2) {
        if (isPrime(i)) {
            v.push_back(i);
            conta++;
        }
    }


    

    cin >> n;
    while(n!=0){
        m=0;
        vector <unsigned long long> numeros;
        for(unsigned long long i = 0; i < n; i++){
            numeros.push_back(i+1);
        }
        long long j = 0;
        while(numeros.size() > 1){
            m+=v[j]-1;
            
            m = m%numeros.size();
            
            numeros.erase(numeros.begin()+m);
            j++;

        }

        cout<< numeros[0] << endl;
        cin >> n;
        numeros.clear();
    }
}