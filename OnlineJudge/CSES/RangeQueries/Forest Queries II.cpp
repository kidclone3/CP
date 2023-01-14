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

int n, q; 
const int N = 1e3+5;
int t[N][N];

void update(int x, int y, int val) {
    for(; x <= n; x += x &(-x))
        for(int v = y; v <= n; v += v&(-v))
            t[x][v] += val;
}

int get(int x, int y) {
    int res = 0;
    for (; x > 0; x -= x&(-x))
        for(int v = y; v > 0; v -= v&(-v))
            res += t[x][v]; 
    return res;
}

int forest[N][N];

int get(int x1, int y1, int x2, int y2) {
    int top_left, top_right, bot_left, bot_right;
    top_left = get(x1-1, y1-1);
    top_right = get(x2, y1-1);
    bot_left = get(x1-1, y2);
    bot_right = get(x2, y2);
    return bot_right - top_right - bot_left + top_left;
}

int solve() {
    cin >> n >> q;

    FOR(n) {
        string s; cin >> s;
        FOR(j, n) if (s[j] == '*') update(i+1, j+1, 1), forest[i][j] = 1;
    }
    FOR(q) {
        int qq; cin >> qq;
        if (qq == 1) {
            int x, y;
            cin >> x >> y;
            if (forest[x-1][y-1] == 1) update(x, y, -1); else update(x, y, 1);
            forest[x-1][y-1] ^= 1;
        } else {
            int x1, x2, y1, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << get(y1, x1, y2, x2)  << "\n";
        }
        
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}

