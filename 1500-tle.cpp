#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getMid(ll s, ll e) {
    /* Função que retorna o índice do elemento do meio entre dois índices */
    return s + (e - s) / 2;
}

ll getSumUtil(vector <ll> &st, ll ss, ll se, ll qs, ll qe, ll si) {
    /* Função que retorna a soma dos elementos entre dois índices */
    if (qs > se || qe < ss) {   // Se o intervalo de consulta não está contido no intervalo de soma
        return 0;
    }
    if (qs <= ss && qe >= se) { // Se o intervalo de consulta está contido no intervalo de soma
        return st[si];
    }
    ll mid = getMid(ss, se);    // Calcula o índice do meio
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) + 
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);   // Retorna a soma dos elementos entre os filhos da esquerda e da direita
        
}

void updateValueUtil(vector <ll> &st, ll ss, ll se, ll i, ll diff, ll si) {
    /* Função que atualiza o valor de um elemento */
    if (i < ss || i > se) {
        return;
    }
    //cout << "st[" << si << "] = " << st[si] << endl;
    st[si] += diff;
    //cout << "st[" << si << "] = " << st[si] << endl;
    if (ss != se) {
        ll mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}

void updateValue(vector <ll> &st, vector <ll> &arr, ll n, ll i, ll new_val) {
    /* Função que atualiza o valor de um elemento */
    if (i < 0 || i > n - 1) {
        return;
    }
    ll diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n - 1, i, diff, 0);
}

ll getSum(vector <ll> &st, ll n, ll qs, ll qe) {
    /* Função que retorna a soma dos elementos entre dois índices */
    if (qs < 0 || qe > n - 1 || qs > qe) {
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

ll constructSegTreeUtil(vector <ll> &arr, ll ss, ll se, ll si, vector <ll> &st) {
    /* Função que constrói a árvore de segmentos */
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = getMid(ss, se);
    st[si] = constructSegTreeUtil(arr, ss, mid, 2 * si + 1, st) + 
             constructSegTreeUtil(arr, mid + 1, se, 2 * si + 2, st);
    return st[si];
}

vector <ll> constructSegTree(vector <ll> &arr, ll n) {
    /* Função que constrói a árvore de segmentos */

    ll x = (ll)ceil(log2(n));
    ll max_size = 2 * (ll)pow(2, x) - 1;
    vector <ll> st(max_size, 0);

    constructSegTreeUtil(arr, 0, n - 1, 0, st);
    return st;
}

int main(){
    ll n;
    cin >> n;

    while(n--){
        ll nn, c;
        cin >> nn >> c;
        vector <ll> arr(nn, 0);
        
        vector <ll> st = constructSegTree(arr, nn);
        while(c--){
            ll op, p, q, v;
            cin >> op >> p >> q;
            p--; q--;
            if(op == 0){
                cin >> v;
                for(ll i = p; i <= q; i++){
                    ll nv = arr[i] + v;
                    updateValue(st, arr, nn, i, nv);
                }
            }
            else{
                //cout << p << " " << q << " " << nn << endl;
                cout << getSum(st, nn, p, q) << endl;
            }
        }

        arr.clear();
    }
    return 0;
}