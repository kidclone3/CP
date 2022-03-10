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

const int N = 2e6+5;
ll bit[N];

vector<ll> phi(N);


void phi_1_to_n() {
    int n = N;
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        phi[i] = i-1;
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 2*i; j <= n; j+=i) {
            phi[j] -= phi[i];
        }
    }
}


int lower(ll l) {
    ll q = sqrt(2*l) + 3;
    FOR(6) {
        if (q*(q+1)/2 < l) return q+1;
        q--;
    }
    return -1;
}

int upper(ll r) {
    ll q = sqrt(2*r) - 3;
    // Make a greatest round.
    FOR(6) {
        if (q*(q+1)/2 > r) return q-1;
        q++;
    }
    return -1;
}

int solve() {
    ll left, right;
    cin >> left >> right;
    int L, R;
    L = lower(left);
    R = upper(right);
    return bit[R] - bit[L-1];
}

int main()
{
    IOS;
    phi_1_to_n();
    // FOR(21) cout << phi[i] << " ";
    // cout << '\n';
    FOR1(N-3) {
        if (i & 1) 
            bit[i] = bit[i-1] + phi[i]*phi[(i+1)/2];
        else {
            bit[i] = bit[i-1] + phi[i/2]*phi[i+1];
        }
    }
    int t; cin >> t;
    while(t--)
        solve();
}

