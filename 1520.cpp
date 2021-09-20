#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

int main(){
    llu n, x ,y, z;
    vector <llu> v(105, 0);
    llu maior = 0;


    while(cin >> n){
        for(llu i = 0; i < n; i++){
            cin >> x >> y;
            for(llu j = x; j <= y; j++){
                v[j]++;
            }
            if (y > maior) maior = y;
        }

        cin >> z;

        if (v[z] == 0 ){
            printf("%llu not found\n", z);
        }else{
            llu somax = 0, somay = 0;
            for(llu i = 1; i <=maior; i++){
                if (i < z) somax += v[i];
                else if (i == z) {
                    somay += v[i];
                    break;
                }
            }
            if(somay <= 1) somay = 0;
            else somay -=1;
            printf("%llu found from %llu to %llu\n", z, somax, somax+somay);
        }
        v.assign(105, 0);
    }

}