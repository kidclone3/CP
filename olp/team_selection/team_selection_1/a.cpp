#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<bits/extc++.h>

using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_tree; typedef tree<int, null_type,
// less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// multi_ordered_tree; tree.find_by_order(x); tree.order_of_key(x); remove
// element in multi_ordered_tree: tree.erase(--tree.lower_bound(x));
#define ar array
#define vt vector
#define all(v) begin(v), end(v)
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
#define FORIT(i, s) for (auto it = (s.begin()); it != (s.end()); ++it)
#define F_OR(i, a, b, s)                                                       \
  for (int i = (a); (s) > 0 ? i < (int)(b) : i > (int)(b); i += (s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n + 1, 1)
#define EACH(x, a) for (auto &x : a)

#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

const int d4x[] = {-1, 0, 1, 0}, d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T> void print(T &x) {
  for (auto &it : x) {
    cerr << it << " ";
  }
  cerr << "\n";
};
template <class T> void printPair(T &x) {
  for (auto &it : x) {
    cerr << "(" << it.first << ", " << it.second << ") ";
  }
  cerr << "\n";
};
const ll MOD = 1e9+9;

long long powMod(long long a, long long n, long long m) {
    long long res = 1LL;
    for(; n > 0; a = a*a % m, n >>= 1) {
        if (n && 1) res = res * a;
    }
    return res;
}

int solve() { 
    ll n, a, b;
    int k;
    cin >> n >> a >> b >> k;
    vl s(k);
    FOR(k) cin >> s[i];
    ll ans = 0LL;
    ll a_k = powMod(powMod(a, k, MOD), MOD-2, MOD);
    FOR(k) {
        ll a_n_i = powMod(powMod(a, n-i, MOD), MOD-2, MOD);
        ll b_i = powMod(powMod(b, i, MOD), MOD-2, MOD);
        ll q_n = powMod
        ans += s[i] * a_n_k * b_k * 
    }
    vl aa(n+5), bb(n+5);
    aa[0] = bb[0] = 1;
    FOR(n+5) {
        aa[i+1] = a*aa[i] % MOD;
        bb[i+1] = b*bb[i] % MOD;
    }
    ll ans = 0;
    FOR(n+1) {
        ans += s[i% k] * aa[n-i]*bb[i] % MOD;
    }
    cout << ans;
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
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}

