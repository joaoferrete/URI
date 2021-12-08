#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    string s = "";
    long k = 1;

    while(cin >> n){
        s = "0";
        unsigned long long tam = 1;

        for(long long i = 1; i <= n; i++){
            //cout << i<<endl;
            for(long long j = 0; j < i; j++){
                s+= (" " + to_string(i));
                tam++;
            }
        }

        if(tam > 1) cout << "Caso " << k << ": " << tam << " numeros" << endl;
        else cout << "Caso " << k << ": " << tam << " numero" << endl;
        k++;
        cout << s << endl << endl;

    }
}