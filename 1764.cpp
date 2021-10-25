#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src, dest, weight;
};

class Graph{
    public:
    int V, E;   // V = numero de vertices, E = numero de arestas
    edge *edgeList; // Lista de arestas
};

Graph* createGraph(int V, int E){
    /* Função que cria um novo grafo */

    Graph *g = new Graph;
    g->V = V;
    g->E = E;
    g->edgeList = new edge[E];
    return g;
}

class subset{ // Classe que representa um conjunto
    public:
    int parent, rank;
};

int find (subset subsets[], int i){
    /* Função que encontra o conjunto que o elemento pertence */

    if (subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    /* Função que une dois conjuntos */

    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b){
    /* Função que compara dois elementos de uma lista de arestas */

    edge *a1 = (edge *) a;
    edge *b1 = (edge *) b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph * graph){
    /* Função que calcula o MST de um grafo */

    int V = graph->V, E = graph->E;
    edge result[V];
    int e = 0; // e = numero de arestas do MST
    int i = 0; // 

    qsort(graph->edgeList, graph->E, sizeof(graph->edgeList[0]), myComp);

    subset *subsets = new subset[V * sizeof(subset)];

    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1){
        edge next_edge = graph->edgeList[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    //cout << "Arestas do MST: " << endl;
    long long sum = 0;
    for (i = 0; i < e; ++i){
        sum+=result[i].weight;
    }
    cout << sum << endl;
}

int main(){
    int m, n;
    cin >> m >> n;
    while(m != 0 && n != 0){
        Graph *g = createGraph(m, n);
        for (int i = 0; i < n; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            g->edgeList[i].src = a;
            g->edgeList[i].dest = b;
            g->edgeList[i].weight = w;
        }
        KruskalMST(g);
        cin >> m >> n;
        delete g;
    }
    
}
