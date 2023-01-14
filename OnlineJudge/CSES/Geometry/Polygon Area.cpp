#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef ll T;
struct point {
    T x, y;
    point() {x = 0, y = 0;}
    point(T _x, T _y) : x(_x), y(_y) {}
    point operator+ (point p) {return {x+p.x, y-p.y};}
    point operator- (point p) {return {x-p.x, y-p.y};}
};

T dot(point a, point b) {return a.x*b.x + a.y*b.y;}
T cross(point a, point b) {return a.x*b.y - a.y*b.x;}

int solve() {
    int n; cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    // reverse(begin(a), end(a));
    T ans = 0LL;
    for(int i = 0; i < n; ++i) {
        // cerr << a[i].x << " " << a[i].y << '\n';
        // cerr << "ans: " << ans << '\n';
        ans += cross(a[i], a[(i+1)%n]);
    }
    cout << abs(ans);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

