#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

typedef struct time{
    llu id;
    llu ponto;
    llu marcado;
    llu recebido;

    time(){
        id = 0;
        ponto = 0;
        marcado = 0;
        recebido = 0;
    }
} Time;

long double avarage(Time a){
    long double x = a.recebido == 0 ? a.marcado : (long double) a.marcado / a.recebido;
    return x;
}

bool ordena(Time a, Time b){
    if(a.ponto == b.ponto){
        if(avarage(a) == avarage(b)){
            if(a.marcado == b.marcado){
                return a.id < b.id;
            }
            return a.marcado > b.marcado;
        }
        return avarage(a) > avarage(b);
    }
    return a.ponto > b.ponto;
}

int main(){
    llu n, x, y, z, w, i=1;
    bool flag = false;

    while(true){
        cin >> n;
        if(n == 0) break;
        if (flag) cout << endl;
        flag = true;


        cout << "Instancia " << i++ << endl;
        vector<Time> times(n);
        for(llu j=0; j<(n * (n-1) / 2); ++j){
            cin >> x >> y >> z >> w;
            times[x-1].id = x;
            times[x-1].marcado += y;
            times[x-1].recebido += w;
            times[z-1].id = z;
            times[z-1].marcado += w;
            times[z-1].recebido += y;

            if(y > w){
                times[x-1].ponto += 2;
                times[z-1].ponto += 1;
            }
            else{
                times[x-1].ponto += 1;
                times[z-1].ponto += 2;
            }
        }
        sort(times.begin(), times.end(), ordena);
        
        for(llu j=0; j<n; ++j){
            if(j == n-1) cout << times[j].id << endl;
            else cout << times[j].id << " ";
        }
    }
}