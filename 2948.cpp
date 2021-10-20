#include <bits/stdc++.h>
using namespace std;

#define eps 1e-6

typedef struct point{
    double x, y;
    point(){}
    point(double _x, double _y){x = _x; y = _y;}

    point subtract(point p){
        return point(x - p.x, y - p.y);
    }
    void read(){
        scanf("%lf %lf", &x, &y);
    }
    double dist(point p){
        return hypot(x - p.x, y - p.y);
    }
    double cross(point p){
        return x * p.y - y * p.x;
    }
    double norm(){
        return (x * x + y * y);
    }
}point;

typedef struct circle{
    point c;
    double r;
    circle(){}
    circle(point _c, double _r){c = _c; r = _r;}

    circle(double a, double b, double _r){
        c = point(a, b);
        r = _r;
    }

    bool contains(point p){
        return c.dist(p) <= (r + eps);
    }

    bool contains(vector <point> p){
        for (auto i: p) if (!contains(i)) return false;
        return true;
    }
}circle;

circle *makeCircumcicle(point a, point b, point c){
    double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2.0;
    if (d == 0) return NULL;
    
    double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
    double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
    point p = point(x, y);

    return new circle(p, p.dist(a));
}

circle makeDiameter(point a, point b){
    point p = point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
    return circle(p, p.dist(a));
}

circle makeCircleTwoPoints(vector <point> p, point pt, point q){
    circle temp = makeDiameter(pt, q);
    if (temp.contains(p)) return temp;

    circle * left = NULL;
    circle * right = NULL;

    for (auto i: p){
        point pq = q.subtract(pt);
        double cross = pq.cross(i.subtract(pt));

        circle  *c = makeCircumcicle(pt, q, i);
        if (c == NULL) continue;
        else if (cross > 0 && (left == NULL || pq.cross(c->c.subtract(pt)) > pq.cross(left->c.subtract(pt)))) left = c;
        else if (cross < 0 && (right == NULL || pq.cross(c->c.subtract(pt)) < pq.cross(right->c.subtract(pt)))) right = c;
    }
    if (right == NULL || (left != NULL && left->r <= right->r)) return *left;
    else return *right;

}

circle makeCircleOnePoint(vector <point> p, point pt){
    circle c = circle(pt, 0);

    for(int i = 0; i < p.size(); ++i){
        point q = p[i];
        if (!c.contains(q)){
            if(c.r == 0) c = makeDiameter(pt, q);
            else {
                vector <point> aux (&p[0], &p[i+1]);
                c = makeCircleTwoPoints(aux, pt, q);
            }
        }
    }
    return c;
}

circle makeCircle(vector <point> p){
    vector <point> aux = p;
    random_shuffle(aux.begin(), aux.end());

    circle c;
    bool flag = true;

    for(int i=0; i<aux.size(); ++i){
        point pt = aux[i];
        if (flag || !c.contains(pt)){
            vector <point> aux2 (&aux[0], &aux[i+1]);
            c = makeCircleOnePoint(aux2, pt);
            flag = false;
        }
    }
    return c;
}


int main(){
    int n;
    cin >> n;
    vector <point> points;

    for(int i=0; i<n; i++){
        point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    circle c = makeCircle(points);

    cout << fixed << setprecision(2) << c.c.x << " " << c.c.y << " " << c.r << " " << 2*c.r*3.14*4 << endl;
  
}
