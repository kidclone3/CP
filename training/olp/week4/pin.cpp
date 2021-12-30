#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
 
// Disable this pragma by default because of debugging
// #pragma GCC optimize("O3,unroll-loops")
 
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors
 
struct Point {
    int x, y;
};
 
bool isOverLap(Point l1, Point r1, Point l2, Point r2) {
    if (l1.x == r1.x || l1.y == r1.y || l2.x == r2.x || l2.y == r2.y) return false;
	if (l1.x >= r2.x || l2.x >= r1.x) return false;
	if (l1.y >= r2.y || l2.y >= r1.y) return false;
	return true;
}
 
int solve() {
    int n; cin >> n;
    vector<pair<Point, Point>> a(n);
    FOR(n) {
        Point l, r;
        cin >> l.x >> l.y >> r.x >> r.y;
        a[i] = {l, r};
    }
    ll ans = 0;
    FOR(i, n) {
    	FOR(j, n) {
    		if (i == j)  continue;
    		ans += isOverLap(a[i].fi, a[i].se, a[j].fi, a[j].se);
    	}
    }
    cout << ans/2;
    return 0; 
}
 
int main()
{
    IOS;
    solve();
}