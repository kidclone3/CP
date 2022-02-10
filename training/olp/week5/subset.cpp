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

int ST[N];

void update(int i, int val) {
    for(; i < N; i += i & -i) ST[i] += val;
}

int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & -i) ans += ST[i];
    return ans;
}

const ll MOD = 1e9+7;

ll addMod(ll a, ll b) {return ((a+b) % MOD + MOD) % MOD;}

ll powMod(ll x, ll n) {
    ll ans = 1LL;
    for(; n; x = (ll) x*x % MOD, n >>= 1)
        if (n & 1) ans = (ll) ans*x % MOD;
    return ans;
}

int solve() {
    int n, q; cin >> n >> q;
    vi a(n+1);
    FOR1(n) {
        cin >> a[i];
        if (a[i] & 1) update(i, 1);
    }
    FOR(q) {
        ll qq, l, r; cin >> qq >> l >> r;
        if (qq == 2) {
            ll le = get(r) - get(l-1);
            ll chan = (r-l+1) - le;
            ll sl_chan = addMod(powMod(2, chan), - 1);
            ll sl_le;
            if (le == 0) sl_le = 0;
            else sl_le = addMod(powMod(2, le-1), -1);
            ll ans = addMod((sl_chan + sl_le) % MOD, sl_chan * sl_le % MOD);
            cout << ans << "\n";
            // cout << "\t" << sl_chan << " " << sl_le << '\n';
        } else {
            if ((a[l] & 1) != (r & 1)) {
                if (r & 1) {
                    update(l, 1);
                } else update(l, -1);
                a[l] = r;
            }
        }
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}