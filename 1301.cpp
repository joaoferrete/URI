#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll st[4 * 100004];
int arr[100004];

int descobreSinal(ll a){
    if(a < 0) return -1;
    else if(a > 0) return 1;
    else return 0;
}


ll getMid(ll s, ll e) {
    /* Função que retorna o índice do elemento do meio entre dois índices */
    return s + (e - s) / 2;
}

void constructSegTree(int arr[], ll i, ll a, ll b, ll *segTree){
    /* Função que constrói a árvore de segmentos */
    if(a == b){
        segTree[i] = descobreSinal(arr[a]);
        return;
    }
    ll mid = getMid(a, b);
    constructSegTree(arr, 2 * i + 1, a, mid, segTree);
    constructSegTree(arr, 2 * i + 2, mid + 1, b, segTree);
    segTree[i] = segTree[2 * i + 1] * segTree[2 * i + 2];
}

void updateSegTree(ll *segTree, ll index, ll a, ll b, ll i, ll val){
    /* Função que atualiza o valor de um elemento da árvore de segmentos */
    if(i > b || i < a) return;
    
    if(a == b && b == i){
        segTree[index] = val;
        return;
    }

    ll mid = getMid(a, b);
    updateSegTree(segTree, 2 * index + 1, a, mid, i, val);
    updateSegTree(segTree, 2 * index + 2, mid + 1, b, i, val);

    segTree[index] = segTree[2 * index + 1] * segTree[2 * index + 2];
}

ll query(ll segTree[], ll index, ll a, ll b, ll i, ll j){
    /* Função que retorna o valor da multiplicação dos elementos entre dois índices */
    if(i > b || j < a) return 1;
    if(a >= i && b <= j) return segTree[index];
    ll mid = getMid(a, b);
    return query(segTree, 2 * index + 1, a, mid, i, j) * query(segTree, 2 * index + 2, mid + 1, b, i, j);
}

int main(){
    ll n, k;

    while(cin >> n >> k){
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        constructSegTree(arr, 0, 0, n - 1, st);

        for (ll i=0; i < k; i++){
            /*
            for(ll j = 0; j < st.size(); j++){
                cout << st[j] << " ";
            }
            cout << endl;*/

            string s;
            cin >> s;
            if (s == "C"){
                ll x, v;
                cin >> x >> v;
                updateSegTree(st, 0, 0, n - 1, x - 1, descobreSinal(v));
            }   
            else{
                ll x, y;
                cin >> x >> y;

                ll a = query(st, 0, 0, n - 1, x - 1, y - 1);

                //cout << a << endl;
                if (a == 0) cout << "0";
                else if (a == 1) cout << "+";
                else cout << "-";
            }
        }
        cout << endl;
    
    }
}