#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// 2 pragma lines give compiler information to use SIMD instruction for optimize code.
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")


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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Small tips on unordered_map to not be tle:
// unordered_map<int, int> mp;
// mp.max_load_factor(0.25);
// mp.reserve(1<<20);

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 2e5+5;

ll t[4*N], d[4*N];
int n, q;
ll a[N], b[4*N];
// I Had to use slow segtree. WLOG.
void build(int id = 1, int l = 0, int r = n-1) {
    if (l == r) {
        t[id] = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(id << 1, l, m);
    build(id << 1 | 1, m+1, r);
    t[id] = t[id<<1] + t[id<<1|1];
}

void push(int id) {
    t[id<<1] += d[id];
    t[id<<1|1] += d[id];
    d[id<<1] += d[id];
    d[id<<1|1] += d[id];
    d[id] = 0;
}

void update(int id, int l, int r, ll val, int l0 = 0, int r0 = n-1) {
    if (r0 < l || r < l0) return;
    if (l <= l0 && r0 <= r) {
        t[id] += val;
        d[id] += val;
        return;
    }
    int mid = (l0+r0) >> 1;
    push(id);
    update(id << 1, l, r, val, l0, mid);
    update(id << 1 | 1, l, r, val, mid+1, r0);
    t[id] = t[id<<1] + t[id<<1|1];
}

ll get(int id, int l, int r, int l0 = 0, int r0 = n-1) {
    if (r0 < l || r < l0) return 0LL;
    if (l <= l0 && r0 <= r) return t[id];
    push(id);
    int mid = (l0+r0) >> 1;
    return get(id << 1, l, r, l0, mid) + get(id << 1 | 1, l, r, mid+1, r0);
}

// This is for query 2.

void push2(int id) {
    b[id<<1] += d[id];
    b[id<<1|1] += d[id];
    d[id<<1] = d[id<<1|1] = d[id];
    d[id] = 0;
}

void update2(int id, int l, int r, ll val, int l0 = 0, int r0 = n-1) {
    if (r0 < l || r < l0) return;
    if (l <= l0 && r0 <= r) {
        b[id] += val;
        d[id] = val;
        return;
    }
    int mid = (l0+r0) >> 1;
    if (d[id] != 0)
        push2(id);
    update2(id << 1, l, r, val, l0, mid);
    update2(id << 1 | 1, l, r, val, mid+1, r0);
    b[id] = b[id << 1] + b[id << 1 | 1];
    t[id] = b[id];
}

int solve() {
    cin >> n >> q;
    FOR(n) cin >> a[i];
    build();
    // h = sizeof(int) * 8 - __builtin_clz(n);
    FOR(q) {
        int qq; 
        int u,v;
        ll x;
        cin >> qq >> u >> v;
        u--, v--;
        if (qq == 1) {
            cin >> x; 
            update(1, u, v, x);
        } else if (qq == 2) {
            cin >> x; 
            memset(b, 0, 4*(n+5)*sizeof(b[0]));
            update2(1, u, v, x);
        } else {
            cout << get(1, u, v) << '\n';
        }
    } 
    return 0; 
}

int main()
{
    IOS;
    solve();
}

