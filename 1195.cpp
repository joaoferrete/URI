#include <bits/stdc++.h>
using namespace std;

typedef struct no{
    int info;
    struct no *dir, *esq;

    no(int info){
        this->info = info;
        this->dir = NULL;
        this->esq = NULL;
    }
}no;

no * insereTree(no *raiz, int info){
    if(raiz == NULL){
        raiz = new no(info);

    }else if(info < raiz->info){
        raiz->esq = insereTree(raiz->esq, info);
    }else{
        raiz->dir = insereTree(raiz->dir, info);
    }
    return raiz;
}

void printInOrder(no *raiz, vector <int> &v){
    if(raiz != NULL){
        printInOrder(raiz->esq, v);
        v.push_back(raiz->info);
        printInOrder(raiz->dir, v);
    }
}
void printPreOrder(no *raiz, vector <int> &v){
    if(raiz != NULL){
        v.push_back(raiz->info);
        printPreOrder(raiz->esq, v);
        printPreOrder(raiz->dir, v);
    }
}

void printPostfix(no *raiz, vector <int> &v){
    if(raiz == NULL){
        return;
    }
    printPostfix(raiz->esq, v);
    printPostfix(raiz->dir, v);
    v.push_back(raiz->info);
}

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        if( i != v.size()-1) cout << v[i] << " ";
        else cout << v[i];
    }
    cout << endl;
}

void destroyTree(no *raiz){
    if(raiz == NULL){
        return;
    }
    destroyTree(raiz->esq);
    destroyTree(raiz->dir);
    delete raiz;
}

int main(){
    int n;
    cin >> n;
    no *raiz = NULL;
    int conta = 1;

    while(n--){
        int a;
        cin >> a;
        for(int i = 0; i < a; i++){
            int b;
            cin >> b;
            raiz = insereTree(raiz, b);
        }
        vector <int> v;
        cout << "Case " << conta << ":\n";
        cout << "Pre.: ";
        printPreOrder(raiz, v);
        printVector(v);
        v.clear();
        cout << "In..: ";
        printInOrder(raiz, v);
        printVector(v);
        v.clear();
        cout << "Post: ";
        printPostfix(raiz, v);
        printVector(v);
        v.clear();
        cout << endl ;
        destroyTree(raiz);
        raiz = NULL;
        conta++;
    }
}