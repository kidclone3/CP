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

const int N = 2*1e5+5;
const int S = 1<<18;
int n, q;
vl arr;

struct node {
    ll sum, pref;
    node(ll _sum, ll _pref) : sum(_sum), pref(_pref) {}
    node(ll x = 0): sum(x), pref(max(0LL, x)) {}
    friend node operator+ (const node &a, const node&b) {
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
} T[S<<1];

void build(int k = 1, int l = 0, int r = n-1) {
    if (l == r) {T[k] = node(arr[l]); return;}
    int m = (l+r)>>1;
    build(k<<1, l, m);
    build(k<<1|1, m+1, r);
    T[k] = T[k<<1] + T[k<<1|1];
}

void update(int p, ll val, int k= 1, int l = 0, int r = n-1) {
    if (l == r) {
        T[k] = node(val); return;
    }
    int m = (l+r)>>1;
    if (p <= m) update(p, val, k<<1, l, m);
    else update(p, val, k<<1|1, m+1, r);
    T[k] = T[k<<1] + T[k<<1|1];
}

node query(int ql, int qr, int k = 1, int l=0, int r=n-1) {
    if (ql > r || l > qr) return 0;
    if (ql <= l && r <= qr) return T[k];
    int m = (l+r)/2;
    node q1 = query(ql, qr, k<<1, l, m);
    node q2 = query(ql, qr, k<<1|1, m+1, r);
    return q1+q2;
}

int solve() {
    cin >> n >> q;
    // vl arr(n);
    arr.resize(n);
    FOR(n) {
        cin >> arr[i];
    }
    build();
    FOR(q) {
        int qq;
        ll a, b;
        cin >> qq >> a >> b;
        if (qq == 1) {
            update(a-1, b);
            arr[a-1] = b;
        } else {
            cout << query(a-1, b-1).pref << "\n";
        }
    }
    // FOR(n<<1) cout << T[i].sum << " \n"[i==2*n-1];
    return 0; 
}

int main()
{
    IOS;
    solve();
}
