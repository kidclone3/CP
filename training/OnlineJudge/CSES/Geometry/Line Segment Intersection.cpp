#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
typedef double T;
struct point {
    T x, y; 
    point() {x = 0, y = 0;}
    point(T _x, T _y) : x(_x), y(_y) {} 
    point operator+(point p) {return {x+p.x, y+p.y};}
    point operator-(point p) {return {x-p.x, y-p.y};}
    point operator*(T d) {return {x*d, y*d};}
    point operator/(T d) {return {x/d, y/d};}
};

T dot(point v, point w) {return v.x*w.x + v.y*w.y;}
T cross(point v, point w) {return v.x*w.y - v.y*w.x;}
T orient(point a, point b, point c) {return cross(b-a, c-a);}

bool inDisk(point a, point b, point p) {
    return dot(a-p, b-p) <= 0;
}

bool onSegment(point a, point b, point p) {
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool properIntersect(vector<point> &vt) {
    point a,b,c,d;
    a = vt[0],
    b = vt[1],
    c = vt[2],
    d = vt[3];
    T oa = orient(c,d,a),
      ob = orient(c,d,b),
      oc = orient(a,b,c),
      od = orient(a,b,d);
    if (oa*ob < 0 && oc*od < 0) return true;
    return false;
}

bool isIntersect(vector<point> &vt) {
    if (properIntersect(vt)) return true;

    point a,b,c,d;
    a = vt[0],
    b = vt[1],
    c = vt[2],
    d = vt[3];
    return onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) || onSegment(c, d, b);
}

int solve() {
    vector<point> a(4);
    for(int i = 0; i < 4; ++i) {
        T x, y;
        cin >> x >> y; 
        a[i] = point(x, y);
    }
    cout << (isIntersect(a) ? "YES":"NO") <<'\n';
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}

