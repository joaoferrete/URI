#include <bits/stdc++.h>
using namespace std;

typedef struct point {
    double x, y;
} point;

bool onSegment(point p, point q, point r) {
    /* Verifica se o ponto Q pertence a linha PR */
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(point p, point q, point r) {
    /* Retorna o valor da orientação do vetor (pqr) */
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);  //Angulo entre os pontos pq e pr subtraídos
              
    if (val == 0) return 0; // colinear

    return (val > 0) ? 1 : 2; //1 se pqr está no sentido horário, 2 se anti-horário
}

bool intersect(point p, point q, point r, point s){
    /* Verifica se as retas pq e rs se interceptam */
    int o1 = orientation(p, q, r);
    int o2 = orientation(p, q, s);
    int o3 = orientation(r, s, p);
    int o4 = orientation(r, s, q);

    if (o1 != o2 && o3 != o4) return true; // As retas se interceptam pois satisfazem a regra de orientacão diferente

    if (o1 == 0 && onSegment(p, r, q)) return true; // pq é colinear e está no segmento rs
    if (o2 == 0 && onSegment(p, s, q)) return true; // pq é colinear e está no segmento rs
    if (o3 == 0 && onSegment(r, p, s)) return true; // rs é colinear e está no segmento pq
    if (o4 == 0 && onSegment(r, q, s)) return true; // rs é colinear e está no segmento pq

    return false; // As retas não se interceptam
}

vector <point> convexHull(vector <point> points) {
    /* Retorna o polígono convexo de um conjunto de pontos */
    int n = points.size(), k = 0;

    int ini = 0; // Inicializa o ponto de menor X
    for(int i=1; i<n; i++){     // Encontra o ponto de menor X (mais à esquerda)
        if(points[i].x < points[ini].x)
            ini = i;
    }

    int p = ini;    // p é o ponto de menor X
    vector <point> hull; 

    do{ // Enquanto não tiver sido feita a volta completa
        hull.push_back(points[p]);  // Adiciona o ponto p ao polígono convexo

        int q = (p+1)%n;    // q é o próximo ponto a ser adicionado ao polígono convexo

        for(int i=0; i<n; ++i){  // Busca o próximo ponto q mais anti horário ao p
            if(orientation(points[p], points[i], points[q]) == 2) q = i;
        }
        
        p = q;  // Atualiza o p
    }while(p != ini);

    return hull;    // Retorna o polígono convexo
}

double distancia(vector <point> points){
    point x = points[points.size()-1];
    double dist = sqrt(pow(points[0].x - x.x, 2) + pow(points[0].y - x.y, 2));
    for(int i=0; i<points.size()-1; i++){
        x = points[i];
        dist += sqrt(pow(points[i+1].x - x.x, 2) + pow(points[i+1].y - x.y, 2));
    }
    return dist;
}

int main(){
    int n;
    cin >> n;
    vector <point> points;

    while(n!=0){
        for(int i = 0; i < n ; ++i){
            point p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }
        vector <point> hull = convexHull(points);
        double dist = distancia(hull);
        printf("Tera que comprar uma fita de tamanho %.2lf.\n", dist);
        points.clear();
        cin >> n;
    }
    return 0;
}