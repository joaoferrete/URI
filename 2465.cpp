#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > mat(102, vector <int> (102, 0));
vector <vector <bool> > bandeira(102, vector <bool> (102, false));

void AtualizaBandeira(int x, int y, int n){
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(bandeira[x][y]) return;
    bandeira[x][y] = true;
    if (mat[x][y] <= mat[x+1][y]) AtualizaBandeira(x+1, y, n);
    if (mat[x][y] <= mat[x][y+1]) AtualizaBandeira(x, y+1, n);
    if (x != 0 && mat[x][y] <= mat[x-1][y]) AtualizaBandeira(x-1, y, n);
    if (y != 0 && mat[x][y] <= mat[x][y-1]) AtualizaBandeira(x, y-1, n);
    return;
}


int main(){
    int n, x, y;
    cin >> n >> x >> y;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    --x; --y;
    AtualizaBandeira(x, y, n);
    int qtd = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(bandeira[i][j]) qtd++;
        }
    }
    cout << qtd << endl;
    return 0;
}