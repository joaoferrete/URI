#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

string decToBin(llu n) {
    string s = "";
    while (n > 0) {
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    return s;
}

string atualizaString(string s, llu tam){
    while(s.size() < tam){
        s = "0" + s;
    }
    return s;
}

llu somaBin(string n1, string n2){
    llu soma = 0;
    llu i;

    bool lado = n1.size() > n2.size();
    bool igual = n1.size() == n2.size();

    if(lado){
        n2 = atualizaString(n2, n1.size());
    }else if(!igual){
        n1 = atualizaString(n1, n2.size());
    }

    for (i = 0; i < n1.size() ; ++i) {
        if (n1[i] != n2[i]) {
            soma += pow(2, n1.size() - i - 1);
        }
    }

    return soma;
}

int main(){
    llu n, m;
    while(cin >> n >> m){
        string n1 = decToBin(n);
        string n2 = decToBin(m);
        cout << somaBin(n1, n2) << endl;
    }
    return 0;

}