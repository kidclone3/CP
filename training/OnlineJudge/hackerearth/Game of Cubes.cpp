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
#define F_OR2(i, e) F_OR(i, -1, e, 1)
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
int N, M;
const int MAX_N = 100+5;
char a[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
vt<ii> trace;

void dfs(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) return;
    if (a[i][j] == '.' || vis[i][j]) return;
    vis[i][j] = 1;
    a[i][j] = '.';
    trace.pb({i, j});
    FOR(k, 4) {
        int x = i + d4x[k];
        int y = j + d4y[k];
        dfs(x, y);
    }

}

void process() {
    // Tien hanh don mang.
    // Tao mang danh dau.
    memset(vis, 0, sizeof vis);
    // Tim cac thanh phan lien thong.
    FOR(i, N){
        FOR(j, M) {
            if (a[i][j] == 'x' && !vis[i][j]) {

                trace.clear();
                dfs(i, j); // Tien hanh loang het cac tplt.
                int shift = N;
                EACH(it, trace) {
                    int len = 0;  
                    for(len = it.fi + 1; len < N && a[len][it.se] == '.'; ++len);
                    // Tim xuong vi tri # cua tplt khac, hoac la cham xuong day.
                    // cerr << len << '\n';
                    // cerr << it.fi << " " << it.se << '\n';
                    shift = min(shift, len - it.fi - 1);
                }
                // cerr << shift << '\n';
                EACH(it, trace) {
                    a[it.fi + shift][it.se] = 'x';
                    vis[it.fi + shift][it.se] = 1;
                }
            }
        }
    }

    // Tim cac thanh phan lien thong roi rac.
}

int solve() { 
    cin >> N >> M;
    FOR(N) cin >> a[i];
    int q; cin >> q;
    FOR(q) {
        int x; cin >> x;
        if (i & 1) {
            FOR(j, M-1, -1, -1) if (a[N - x][j] == 'x') {
                a[N - x][j] = '.'; break;
            }
        } else {
            FOR(j, M) if (a[N - x][j] == 'x') {
                a[N - x][j] = '.'; break;
            }
        }

        process();
    }
    FOR(N) cout << a[i] <<"\n";
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

