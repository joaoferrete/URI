#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;

    while(cin >> str){
        long long cont = 0;
        stack <char> s;
        for(int i = 0; i < str.size(); i++){
            if (s.empty()) s.push(str[i]);
            else if (str[i] == 'B' && s.top() == 'S'){
                s.pop();
                cont++;
            }
            else if (str[i] == 'S' && s.top() == 'B'){
                s.pop();
                cont++;
            }
            else if(str[i] == 'C' && s.top() == 'F'){
                s.pop();
                cont++;
            }
            else if(str[i] == 'F' && s.top() == 'C'){
                s.pop();
                cont++;
            }
            else s.push(str[i]);
        }
        cout << cont << endl;
    }
}