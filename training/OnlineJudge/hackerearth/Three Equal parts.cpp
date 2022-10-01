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

const ll MOD = 1000000007;
ll powMod(ll x, ll n) {
  ll ans = 1LL;
  for (; n; x = x * x % MOD, n >>= 1) {
    if (n & 1)
      ans = ans * x % MOD;
  }
  return ans;
}
int solve() {
  int n;
  cin >> n;
  vi a(n, 0);
  FOR(n) cin >> a[i];
  ll big_decimal = 0LL;
  vl dp_left(n), dp_right(n);
  map<int, vi> mp;
  FOR(n) {
    big_decimal = (big_decimal * 2 + a[i]) % MOD;
    dp_left[i] = big_decimal;
  }
  big_decimal = 0LL;
  FOR(i, n-1, -1, -1) {
    if (a[i])
      big_decimal = big_decimal + powMod(2, n - i - 1);

    dp_right[i] = big_decimal;
    mp[big_decimal].push_back(i);
  }
  big_decimal = dp_left[n-1];


  auto check = [&](int i, int j) {
      // i : left, j: right;
    ll mid = dp_left[j-1] - dp_left[i];
    mid -= dp_left[i] * powMod(2, j-i-1) % MOD;
    mid = (mid + MOD) % MOD;
    // cerr << mid << " " << dp_left[i]*powMod(2, j-i) << " " << dp_left[i] << '\n';
    return mid == dp_left[i];
  };
  // EACH(it, mp) cerr << it.fi <<": ", print(it.se);
  FOR(n) {
      if (!mp[dp_left[i]].empty()) {
          EACH(j, mp[dp_left[i]]) {
              if (j <= i) break;
              if (check(i, j)) return cout << dp_left[i] <<'\n', 0;
          }
      }
  }
  cout << "-1\n";

  // print(dp_left);
  // print(dp_right);
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
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
