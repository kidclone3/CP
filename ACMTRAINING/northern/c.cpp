#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include <bits/stdc++.h>
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
          d8x[] = {-1, -2, -1, 0, 0, 1, 2, 1},
          d8y[] = {-1, 0, 1, -2, 2, -1, 0, 1};
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
const int N = 4000;
int n;
int grid[N + 5][N + 5];
int dp[N + 5][N + 5];

int mn = INT_MAX, mx = INT_MIN;

bool check(int i, int j) { return !(i < 0 || i >= N || j < 0 || j >= N); }

int findMaxPath(int i, int j) {
  if (!check(i, j))
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  vi mnn(8, INT_MIN);
  FOR(k, 8) {
    int x = i + d8x[k];
    int y = j + d8y[k];
    if (check(x, y) && grid[x][y]) {
      mnn[k] = 1 + findMaxPath(x, y);
    }
  }
  return dp[i][j] = max(1, *max_element(all(mnn)));
}

int solve() {
  memset(grid, 0, sizeof grid);
  memset(dp, -1, sizeof dp);
  vii a(n);
  // cin >> n;
  FOR(n) {
    cin >> a[i].fi >> a[i].se;
    mn = min({mn, a[i].fi, a[i].se});
    mx = max({mx, a[i].fi, a[i].se});
  }
  FOR(n) { grid[a[i].fi - mn][a[i].se - mn] = 1; }
  FOR(i, 3) FOR(j, 3) cout << grid[i][j] << " \n"[j == 2];
  int result = 1;
  FOR(i, N) FOR(j, N) {
    if (dp[i][j] == -1 && grid[i][j]) {
      findMaxPath(i, j);
      result = max(result, dp[i][j]);
    }
  }
  cout << result;
  return 0;
}
int main() {
  IOS;
  // #ifndef ONLINE_JUDGE
  //   f

  //  #else
  //   // online submission

  while (cin >> n)
    solve();
}


