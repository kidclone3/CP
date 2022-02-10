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

const int N = 1e5+5;
const int MOD = 1e9+7;
vi f(N), g(N), d(N), c(N);

ii T[N];

ii getMax(int x) {
    ii res(0, 1);
    while (x > 0) {
        if (T[x].first > res.first) res = T[x];
        else if (T[x].first == res.first) res.second = (res.second + T[x].second) % MOD;
        x -= x&-x;
    }
    return res;
}

void update(int x, int fi, int gi) {
    while(x < N) {
        if (T[x].first < fi) T[x] = {fi, gi};
        else if (T[x].first == fi) T[x].second = (T[x].second + gi) % MOD;
        x += x&-x;
    }
}

int solve() {
    int n; cin >> n;
    vi a(n); FOR(n) cin >> a[i];
    set<int> tmp(all(a));
    vi b(all(tmp));
    // Rời rạc hóa
    FOR(n) {
        auto lb = lower_bound(all(b), a[i]) - b.begin()+1;
        a[i] = lb;
    }
    // print(a);
    // Dùng BIT
    int mx = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        ii r = getMax(a[i] - 1);
        ii res = getMax(a[i]);
        // ii res_old = res;
        if (res.first < r.first + 1) {
            res.first = r.first + 1;
            res.second = r.second;
        } else if (res.fi == r.fi + 1) {
            res.se = r.se;
        }
        update(a[i], res.fi, res.se);
        // res = getMax(a[i]);
    }
    for(int i = 1; i <= b.size(); ++i) {
        ii res = getMax(i);
        if (res.fi > mx) mx = res.fi, ans = res.se;
        else if (res.fi == mx) ans = max(ans, res.se);
    }
    // FOR1(n) cout << d[i] << " " << c[i] << "\n"[i==n];
    cout << ans;
    return 0; 
}

int main()
{
    IOS;
    solve();
}