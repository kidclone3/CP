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

const ll MOD = 1e9+7;

ll powMod(ll x, ll n) {
    ll ans = 1;
    for(x %= MOD; n; x = x*x % MOD, n >>= 1) {
        if (n &1) ans = ans * x % MOD;
    }
    return ans;
}

ll nCk(ll n, ll k) {
    ll top = 1, down = 1;
    for(ll i = n-k+1; i <= n; ++i) {
        top = top*i % MOD;
    }
    for (ll i = 1; i <= k; ++i) {
        down = down * i % MOD;
    }
    // cout << top << " " << down << "\n";
    down = powMod(down, MOD-2);
    // cout << top << " " << down << "\n";
    return top * down % MOD;
}

int solve() {

    // Cthuc: (n+k-1)C(k-1) với k = số lượng các phần tử. 
    // Ở trong bài, n = m - tổng a[i]
    // k = n.
    ll m, n; cin >> m >> n;
    ll x;
    FOR(n) cin >> x, m -=x;
    if (m < 0) return cout << 0, 0;
    cout << nCk(m+n-1, n-1);
    return 0; 
}

int main()
{
    IOS;
    solve();
}