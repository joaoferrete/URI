#include <bits/stdc++.h>
using namespace std;

int main(){
    int fat[10];
    fat[0] = 1;
    for(int i = 1; i < 10; i++){
        fat[i] = fat[i-1] * i;
    }
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 9; i > -1; --i){
        ans += n / fat[i];
        n %= fat[i];
    }
    cout << ans << endl;
}