#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    int vert;
    struct lista *prox;
}No;

typedef struct list{
    No *inicio;
    No *fim;
    int tam;
}Lista;

typedef struct grafo{
    int v;
    int e;
    Lista **adj;
}Grafo;

typedef struct vertice{
    int no;
    struct vertice *prox;
}Vertice;


Lista * cria_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

Lista * insere_lista(Lista *l, int v){
    No *n = (No*)malloc(sizeof(No));
    n->vert = v;
    n->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = n;
        l->fim = n;
    }else{
        l->fim->prox = n;
        l->fim = n;
    }
    l->tam++;
    return l;
}

Lista * retiraInicio(Lista *l){
    No *n = l->inicio;
    l->inicio = l->inicio->prox;
    l->tam--;
    free(n);
    return l;
}

void libera_lista(Lista *l){
    No *n = l->inicio;
    while(n){
        No *t = n->prox;
        free(n);
        n = t;
    }
    free(l);
}

void liberaGrafo(Grafo *g){
    int i;
    for(i = 0; i < g->v; i++){
        libera_lista(g->adj[i]);
    }
    free(g->adj);
    free(g);
}


Grafo * criaGrafo(int V){
    Grafo * g = (Grafo *) malloc(sizeof(Grafo));
    if(!g) exit(1);
    g->v = V;
    g->e = 0;
    g->adj =(Lista **) malloc(V * sizeof(Lista*));
    if(!g->adj) exit(1);
    int i;
    for(i = 0; i < V; i++){
        g->adj[i] = cria_lista();
    }
    return g;
}

Lista * insereAdj(Grafo *g, int v, int w){
    Lista *l = g->adj[v];
    Lista *l2 = g->adj[w];
    l = insere_lista(l, w);
    l2 = insere_lista(l2, v);
    g->e++;
    return l;
}

int is_bipartite(Grafo *g){
    int *alcancado =(int *) malloc(g->v * sizeof(int));
    int * nivel =(int *) malloc(g->v * sizeof(int));
    Lista * filaVertices = cria_lista();
    int r, v, i;

    for(i = 0; i < g->v; i++){
        alcancado[i] = 0;
        nivel[i] = -1;
    }

    v = 0;
    r = 0;
    filaVertices = insere_lista(filaVertices, v);
    alcancado[v] = r;
    nivel[v] = 0;

    while(filaVertices && filaVertices->tam > 0){
        v = filaVertices->inicio->vert;
        //printf("Vertice: %d\n",filaVertices->inicio->vert);

        No * aux = g->adj[v]->inicio;
        while(aux){
            //printf("Adjacente: %d ", aux->vert);
            if(!alcancado[aux->vert]){
                //printf("Nao alcancado\n");
                filaVertices = insere_lista(filaVertices, aux->vert);
                alcancado[aux->vert] = r = r+1;
                nivel[aux->vert] = nivel[v] + 1;
            }
            else{
                //printf("Alcancado\n");
            }
            if(alcancado[v] < alcancado[aux->vert]){
                if(nivel[v] == nivel[aux->vert]){
                    free(alcancado);
                    free(nivel);
                    libera_lista(filaVertices);
                    return 0;
                }
            }
            aux = aux->prox;
        }
        filaVertices = retiraInicio(filaVertices);
    }
    free(alcancado);
    free(nivel);
    libera_lista(filaVertices);
    return 1;
}
void printAdjacentList(Grafo *g){
    int i;
    for(i = 0; i < g->v; i++){
        No * aux = g->adj[i]->inicio;
        printf("%d: ", i);
        while(aux){
            printf("%d ", aux->vert);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main(){
    long long n;
    while(1){
        scanf("%lld", &n);
        if(n == 0) break;
        Grafo *g = criaGrafo(n);
        int i;
        for(i = 0; i < n; i++){
            int pos;
            scanf("%d", &pos);
            pos--;
            char s[300];
            getchar();
            fgets(s, 300, stdin);
            char *p = strtok(s, " ");
            while(p){
                int w = atoi(p);
                w--;
                g->adj[pos] = insereAdj(g, pos, w);
                p = strtok(NULL, " ");
            }
        }
        //printAdjacentList(g);
        if(is_bipartite(g)) printf("SIM\n");
        else printf("NAO\n");
        liberaGrafo(g);
    }
    return 0;
}



