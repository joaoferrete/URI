#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector <int> s;
    vector <int> v;

    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++){
            s.push_back(i);
        }
        
        while(s.size() > 1){
            v.push_back(s[0]);
            s.erase(s.begin());
            s.push_back(s[0]);
            s.erase(s.begin());
        }
        if(n == 1) printf("Discarded cards:");
        else printf("Discarded cards: 1");
        for(int i = 1; i < v.size(); i++){
            printf(", %d", v[i]);
        }
        printf("\nRemaining card: %d\n", s[0]);
        s.clear();
        v.clear();
    }
}