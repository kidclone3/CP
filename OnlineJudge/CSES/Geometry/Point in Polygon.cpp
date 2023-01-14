#include<bits/stdc++.h>
using namespace std;

#define ll long long 
typedef double T;
struct point{
    T x, y;
    point() {}
    point(T _x, T _y) : x(_x), y(_y) {}
    point(const point &p) : x(p.x), y(p.y) {}
    point operator+(point p) {return {x+p.x, y+p.x};}
    point operator-(point p) {return {x-p.x, y-p.x};}
};

T sq(point p) {return p.x*p.x + p.y*p.y;}
double abs(point p) {return sqrt(sq(p));}

T cross(point v, point w) {return v.x*w.y-v.y*w.x;}
T dot(point v, point w) {return v.x*w.x + v.y*w.y;}
T orient(point a, point b, point c) {return cross(a-c, b-c);}

// To check if point in boundary
bool inDisk(point a, point b, point p) {
    return dot(a-p, b-p) <= 0; 
}

bool onSegment(point a, point b, point p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

// double angle(point v, point w) {
//     double cosTheta = dot(v, w) / abs(v) / abs(w);
//     return acos(max(-1.0, min(1.0, cosTheta)));
// }

// double angleTravelled(point a, point p, point q) {
//     double ampli = angle(p-a, q-a);
//     if (orient(a, p, q) > 0) return ampli;
//     else return -ampli;
// }

// int windingNumber(vector<point> points, point a) {
//     double ampli(0);
//     for(int i = 0, n = (int)points.size(); i < n; ++i) {
//         ampli += angleTravelled(a, points[i], points[(i+1)%n]);
//     }
//     return round(ampli/(2*M_PI));
// }

// True if P at least as higher as A 
bool above(point a, point p) {
    return p.y >= a.y;
}
// Check if [PQ] crosses ray from A.
bool crossesRay(point a, point p, point q) {
    return (above(a, q) - above(a, p)) * orient(p, q, a) > 0;
}

bool inPolygon(vector<point> &a, point p) {
    int numCrossings = 0;
    for(int i = 0, n = a.size(); i < n; ++i) {
        numCrossings += crossesRay(p, a[i], a[(i+1)%n]);
    }
    return numCrossings & 1;
}

string check(vector<point> &a, point p) {
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        if (onSegment(a[i], a[(i+1)%n], p)) {
            // cerr << a[i].x << " " << a[i].y << '\n';
            // cerr << a[(i+1)%n].x << " " << a[(i+1)%n].y << '\n';
            // cerr << orient(p, a[i], a[(i+1)%n]) << '\n';
            return "BOUNDARY";
        }
    }
    return inPolygon(a, p) ? "INSIDE" : "OUTSIDE";
}

int solve() {
    int n, m; cin >> n >> m;
    vector<point> polygon(n), points(m);
    for(int i = 0; i < n; ++i) cin >> polygon[i].x >> polygon[i].y;
    for(int i = 0; i < m; ++i) cin >> points[i].x >> points[i].y;
    
    for(int i = 0 ; i < m; ++i) {
        // cout << points[i].x << " " << points[i].y << "\n";
        cout << check(polygon, points[i]) << '\n';
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

