#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, ans, i;

    while(cin >> n){
        ans=1;
        for(i=1; i%n; i = (i*10+1)%n){
            ans++;
        }
        cout << ans << endl;
    }
}