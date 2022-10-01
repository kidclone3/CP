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
#define BUG(x)                                                                 \
  { cout << #x << " = " << x; }
#define IO                                                                     \
  {                                                                            \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);                                        \
  }
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0);
template <class T> void print(T &x) {
  for (auto &it : x) {
    cout << it << " ";
  }
  cout << "\n";
};
template <class T> void printPair(T &x) {
  for (auto &it : x) {
    cout << "(" << it.first << ", " << it.second << ") ";
  }
  cout << "\n";
};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // S,SE,E,NE,N,NW,W,SW neighbors

const int MOD = 1e9 + 7;
const int BASE = 131;
const int N = 1e6 + 5;
ll hs[2 * N], n;
ll inv[2 * N];

string s;

ll mod(ll a) { return a >= MOD ? a % MOD : a; }

ll powMod(ll x, ll p) {
  ll ans = 1;
  for (; p; x = mod(1LL * x * x), p >>= 1)
    if (p & 1)
      ans = mod(1LL * ans * x);
  return ans;
}

void init() {
  s = s + s;
  ll p = 1;
  hs[0] = 0;
  FOR(i, 0, 2 * n) {
    hs[i + 1] = mod(1LL * (s[i] - 'a' + 1) * p + hs[i]);
    inv[i] = powMod(p, MOD - 2);
    p = mod(1LL * p * BASE);
  }
}

ll gethash(int l, int r) { return mod(1LL * (hs[r] - hs[l] + MOD) * inv[l]); }

int solve() {
  cin >> s;
  n = s.size();
  init();
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int lcp = 0; // longest
    for (int l = 0, r = n - 1; l <= r;) {
      int mid = (l + r) >> 1;
      // int tmp1 = gethash(i, i+mid);
      // int tmp2 = gethash(ans, ans+mid);
      // cout << tmp1 << " " << tmp2 << '\n';
      if (gethash(i, i + mid) == gethash(ans, ans + mid)) {
        lcp = mid;
        // cout << lcp << '\n';
        l = mid + 1;
      } else
        r = mid - 1;
    }
    // cout << lcp << " " << ans << "\n";
    if (lcp == n - 1)
      continue;
    if (s[ans + lcp] > s[i + lcp])
      ans = i;
  }
  // cout << ans << '\n';
  // cout << s << "\n";
  cout << s.substr(ans, n);
  // FOR(n+5) cout << inv[i] << " ";
  return 0;
}

int main() {
  IOS;
  solve();
}
