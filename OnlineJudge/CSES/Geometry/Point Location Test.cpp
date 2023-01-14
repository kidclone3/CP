#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point {
    ll x, y;
    Point (ll _x, ll _y) : x(_x), y(_y) {}
    Point () {}
};

int solve() {
    vector<Point> a(3);
    for(int i = 0; i < 3; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = Point(x, y);
    }
    Point v(-a[1].y+a[0].y, a[1].x - a[0].x);
    ll c = v.x*a[0].x + v.y*a[0].y;
    c = -c;
    ll tmp = a[2].x * v.x + a[2].y*v.y + c;
    if (tmp > 0) cout << "LEFT";
    else if (tmp < 0) cout << "RIGHT";
    else cout << "TOUCH";
    cout << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}

