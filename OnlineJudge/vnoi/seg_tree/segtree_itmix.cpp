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



const ll MOD = 1e9 + 7;
const int N = 1e5+5;
ll ST[4*N];

void update1(int id, int l, int r, int u, int v, ll x) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        ST[id] = ((ll) ST[id] + x) % MOD;
        return;
    }
    int mid = (l+r)/2;
    update1(2*id, l, mid, u, v, x);
    update1(2*id+1, mid+1, r, u, v, x);
    ST[id] = ((ll) ST[2*id] + ST[2*id+1]) % MOD;
}

void update2(int id, int l, int r, int u, int v, ll x) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        ST[id] = ((ll) ST[id] * x) % MOD;
        return;
    }
    int mid = (l+r)/2;
    update2(2*id, l, mid, u, v, x);
    update2(2*id+1, mid+1, r, u, v, x);
    ST[id] = ((ll) ST[2*id] + ST[2*id+1]) % MOD; 
}

void update3(int id, int l, int r, int u, int v, ll x) {
    if (r < u || v < l) return;

    if (u <= l && r <= v) {
        if (l == r)
            ST[id] = x % MOD;
        else {
            ST[id] = (ll) x * (r-l+1) % MOD;
        }
        return;
    }
    int mid = (l+r)/2;
    update3(2*id, l, mid, u, v, x);
    update3(2*id+1, mid+1, r, u, v, x);
    ST[id] = ((ll) ST[2*id] + ST[2*id+1]) % MOD; 
}

ll get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) 
        return ST[id];
    int mid = (l+r)/2;
    int left = get(2*id, l, mid, u, v);
    int right = get(2*id+1, mid+1, r, u, v);
    return ((ll) left + right) % MOD;
}

int solve() {
    int n, m; cin >> n >> m;
    FOR1(n) {
        int x; cin >> x;
        update1(1, 1, n, i, i, x);
    }
    FOR(m) {
        int q, l, r, x;
        cin >> q >> l >> r;
        if (q == 4) {
            cout << get(1, 1, n, l, r) << "\n";
        } else {
            cin >> x;
            if (q == 1) update1(1, 1, n, l, r, x);
            if (q == 2) update2(1, 1, n, l, r, x);
            if (q == 3) update3(1, 1, n, l, r, x);
        }
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}