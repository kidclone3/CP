#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second <<") ";
    }
    cerr << "\n";
};
const ll MOD = (ll) 1e9+7;
struct matrix {
    // vvl val(2, vl(2, 0));
    vvl val;
    matrix() {
        val = {{1LL, 0LL}, {0LL,1LL}};
    }
    void base_init() {
        val = {{0LL, 1LL}, {1LL, 1LL}};
    }
    void zero_init() {
        val = {{0LL, 0LL}, {0LL, 0LL}};
    }
};

matrix mul(matrix &a, matrix &b) {
    matrix ans;
    ans.zero_init();
    FOR(i, 2)
        FOR(j, 2)
            FOR(k, 2) {
                ans.val[i][j] += (a.val[i][k] * b.val[k][j]) % MOD;
                ans.val[i][j] %= MOD;
            }
    return ans;
}

matrix powMod(ll x) {
    matrix base;
    base.base_init();
    matrix ans = matrix();
    for(; x > 0; base = mul(base, base), x >>= 1) 
        if (x & 1) ans = mul(ans, base);
    return ans;
}

int solve() {
    ll n; cin >> n;
    if (n == 0) return cout << 0, 0;
    if (n == 1) return cout << 1, 0;
    matrix ans = powMod(n-1);
    cout << ans.val[1][1];
    return 0;
}
int main() {
    IOS;
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#else
	// online submission
#endif
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        cout << "\n";
    } 
    return 0; 
}

