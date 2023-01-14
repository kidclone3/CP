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
const int N = 100+5;
vvi visited(N, vi(N, 0)); // 0 = not visited, 1 = visited first time, 2 = visit second time
vvi len(N, vi(N, 0)); // 0 = not visited, 1 = visited first time, 2 = visit second time
vvi a(N, vi(N));
int n, m; 
bool inside(int u, int v) {
  return 1 <= u && u <= n && 1 <= v && v <= m;
}
// Finding first circle in graph
// {first, second} = 
// First = length to circle
// Second = is stop point or not?
int cnt = 0;
void dfs(int u, int v, ii &start_c, ii &end_c) {
  visited[u][v] = 1;
  cnt++;
  len[u][v] = cnt;
  int x = u, y = v;
  switch(a[u][v]) {
    case 0: x -=1 ; break;
    case 1: x +=1; break;
    case 2: y -= 1; break;
    case 3: y+= 1; break;
  }
  // cerr << "\t" << x <<  " " << y << '\n';
  int res = 1;
  if (inside(x, y)) {
    if (visited[x][y]) {
      start_c = {x, y};
      end_c = {u, v};
      return;
    } else dfs(x, y, start_c, end_c);
  } else {
    start_c = {u, v};
    end_c = {u, v};
    return;
  }
}
void dfs2(int u, int v, ii &start_c, int k) {
  cnt++;
  visited[u][v] = 1;
  if (cnt == k) {
    start_c = {u, v};
    return;
  }
  int x = u, y = v;
  switch(a[u][v]) {
    case 0: x -=1 ; break;
    case 1: x +=1; break;
    case 2: y -= 1; break;
    case 3: y+= 1; break;
  }
  dfs2(x, y, start_c, k);
}

int solve() { 
    cin >> n >> m;
    FOR(i, 1, n+1) FOR(j,1, m+1) cin >> a[i][j];
    ll k; cin >> k;
    ii start_c, end_c;
    dfs(1, 1, start_c, end_c);
    // cout << cnt;
    if (k <= cnt) {
      FOR(N) visited[i].assign(N, 0);
      cnt = 0;
      dfs2(1, 1, start_c, k);
      cout << start_c.fi << " " << start_c.se;
    } else {
      // cerr << start_c.fi << " " << start_c.se <<'\n';
      // cerr << end_c.fi << " " << end_c.se << '\n';
      if (start_c.fi == end_c.fi && start_c.se == end_c.se) {
        cout << start_c.fi << " " << start_c.se;
      } else {
        int circle_len = len[end_c.fi][end_c.se] - len[start_c.fi][start_c.se] +1;
        // cerr << circle_len <<'\n';
        int straight_len = cnt - circle_len;
        k -= straight_len;
        k %= circle_len;
        k += 1;
        FOR(N) visited[i].assign(N, 0);
        cnt = 0;
        dfs2(start_c.fi, start_c.se, end_c, k);
        cout << end_c.fi << " " << end_c.se;
      }
    }
    // cerr << circle_x << " " << circle_y <<'\n';
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
      
  solve();
  return 0;
}

