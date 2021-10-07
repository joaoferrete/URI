#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;

typedef struct Node {
    int lin;
    int col;
    llu data;
    struct Node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} List;

List * createList() {
    List *l = new List;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void insertList(List *l, int lin, int col, llu data) {
    node *n = new node;
    n->lin = lin;
    n->col = col;
    n->data = data;
    n->next = NULL;
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
}

/*
void printList(List *l) {
    node *aux = l->head;
    while(aux != NULL) {
        cout << "(" << aux->lin << ", " << aux->col << ") = " << aux->data << endl;
        aux = aux->next;
    }
}
*/

llu sumFromList(List *l, int x, int y, int z, int w) {
    node *aux = l->head;
    llu sum = 0;
    while(aux != NULL) {
        if (aux->lin >= x && aux->col >= y && aux->lin <= z && aux->col <= w) {
            sum += aux->data;
        }
        aux = aux->next;
    }
    return sum;
}

void freeList(List *l) {
    node *aux = l->head;
    while(aux != NULL) {
        node *aux2 = aux;
        aux = aux->next;
        delete aux2;
    }
    delete l;
}


int main(){
    llu x, y, p, q;
    List *l;

    while(true){
        cin >> x >> y >> p;
        if(x == 0 && y == 0 && p == 0) break;
        
        cin>>q;
        l = createList();
        
        while(q--){
            string a;
            cin >> a;

            if(a=="A"){
                llu n, i, j;
                cin >> n >> i >> j;
                insertList(l, i, j, n);
            }
            else{
                llu I, J, Z, W, i, j, z, w;
                cin >> I >> J >> Z >> W;
                
                i  = I < Z ? I : Z;
                j  = J < W ? J : W;
                z  = I >= Z ? I : Z;
                w  = J >= W ? J : W;

                cout << sumFromList(l, i, j, z, w)*p << endl;
            }
        }
        cout<<endl;
        freeList(l);

    }
}