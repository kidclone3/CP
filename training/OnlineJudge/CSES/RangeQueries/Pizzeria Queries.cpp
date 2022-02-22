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

// Small tips on ordered_map to not be tle:
// unordered_map<int, int> mp;
// mp.max_load_factor(0.25);
// mp.reserve(1<<20);

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

template<class T> struct SegTree {
    const int N = 2e5+5;
    int n; 
    T upb = 1e9;
    vector<T> t; 
    SegTree() {}
    SegTree(int _n) : n(_n), t(2*n, upb) {}
    
    T F(T a, T b) {return min(a, b);}

    void build() {
        for(int i = n-1; i > 0; --i) t[i] = F(t[i<<1], t[i<<1|1]);
    }

    void upd(int p, T val) {
        for(t[p+=n] = val; p > 1; p >>=1) t[p>>1] = F(t[p], t[p^1]);
    }

    T qry(int l, int r) { // min on interval [l, r)
        T res = upb;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = F(res, t[l++]);
            if (r & 1) res = F(res, t[--r]);
        }
        return res;
    }
};

int solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    SegTree<int> down(n), up(n);
    FOR(n) {
        cin >> a[i];
        down.t[i+n] = a[i] - i;
        up.t[i+n] = a[i] + i;
    }
    down.build();
    up.build();
    FOR(q) {
        int typ; cin >> typ;
        if (typ == 2) {
            int pos; cin >> pos;
            pos--;
            int D = down.qry(0, pos+1) + pos;
            int U = up.qry(pos, n) - pos;
            cout << min(D, U) << "\n";
        } else {
            int pos, x;
            cin >> pos >> x;
            pos--;
            a[pos] = x;
            down.upd(pos, x-pos);
            up.upd(pos, x+pos);
        }
    }
    // print(up.t);
    return 0; 
}

int main()
{
    IOS;
    solve();
}