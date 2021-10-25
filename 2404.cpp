#include <bits/stdc++.h>
using namespace std;

//Numero de vertices
#define V 502

int minKey(int key[], bool mstSet[], int n){
    /* Função que retorna o indice do elemento com menor key */

    //inicializando o menor valor como infinito
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], vector<vector<int>> graph, int n){
    /* Função que imprime o MST */

    long total = 0;
    for (int i = 1; i < n; i++)
        total += graph[parent[i]][i];
    cout<<total<<endl;
}

void primMST(vector<vector<int>> graph, int n){
    /* Implementação do algoritmo de PRIN para
    encontrar a árvore geradora mínima */

    int parent[n]; //parent[i] = pai do vertice i

    int key[n]; //key[i] = custo do vertice i

    bool mstSet[n]; //mstSet[i] = true se o vertice i está no MST

    //inicializando os vetores
    for(int i = 0; i < n; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    //inicializando o primeiro vertice como 0
    key[0] = 0;
    parent[0] = -1;

    //enquanto o MST não estiver completo
    for(int count = 0; count < n-1; ++count){
        //encontra o vertice com menor key
        int u = minKey(key, mstSet, n);

        //marca o vertice como visitado
        mstSet[u] = true;

        //atualiza o custo do vertice
        for(int v = 0; v < n; v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    //imprime o MST
    printMST(parent, graph, n);
}

int main(){
    vector<vector<int>> graph(V, vector<int>(V, 0));
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1][b-1] = c;
        graph[b-1][a-1] = c;
    }

    primMST(graph, n);
    return 0;
    
}
