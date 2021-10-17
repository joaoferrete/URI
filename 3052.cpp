#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <string> mat(n);
    for(int i = 0; i < n; i++){
        cin >> mat[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == '.'){
                if(i > 0 && mat[i-1][j] == 'o') mat[i][j] = 'o';
                else if(j > 0 && i < n-1 && mat[i][j-1] == 'o' && mat[i+1][j-1] == '#') mat[i][j] = 'o';
                else if(i < n-1 && j < m-1 && mat[i][j+1] == 'o' && mat[i+1][j+1] == '#') mat[i][j] = 'o';
            }
        }
        for(int j = m-1; j > -1; --j){
            if(mat[i][j] == '.'){
                if(i > 0 && mat[i-1][j] == 'o') mat[i][j] = 'o';
                else if(j > 0 && i < n-1 && mat[i][j-1] == 'o' && mat[i+1][j-1] == '#') mat[i][j] = 'o';
                else if(i < n-1 && j < m-1 && mat[i][j+1] == 'o' && mat[i+1][j+1] == '#') mat[i][j] = 'o';
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = m-1; j > -1; --j){
            if(mat[i][j] == '.'){
                if(i > 0 && mat[i-1][j] == 'o') mat[i][j] = 'o';
                else if(j > 0 && i < n-1 && mat[i][j-1] == 'o' && mat[i+1][j-1] == '#') mat[i][j] = 'o';
                else if(i < n-1 && j < m-1 && mat[i][j+1] == 'o' && mat[i+1][j+1] == '#') mat[i][j] = 'o';
            }
        }
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == '.'){
                if(i > 0 && mat[i-1][j] == 'o') mat[i][j] = 'o';
                else if(j > 0 && i < n-1 && mat[i][j-1] == 'o' && mat[i+1][j-1] == '#') mat[i][j] = 'o';
                else if(i < n-1 && j < m-1 && mat[i][j+1] == 'o' && mat[i+1][j+1] == '#') mat[i][j] = 'o';
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << mat[i] << endl;
    }
    return 0;
}