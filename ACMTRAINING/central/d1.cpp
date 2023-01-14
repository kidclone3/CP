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

int block;

struct query {
  int L, R, pos;
};

bool cmp(query &a, query &b) {
  if (a.L / block != b.L / block)
    return a.L / block < b.L / block;
  else
    return a.R < b.R;
}

const int N = 1e5 + 5;
const int LOGN = __lg(N);
int bit[N + 5];

int n, q;

void update(int i, int val) {
  for (; i <= N; i += i & (-i))
    bit[i] += val;
}

int get(int i) {
  int res = 0;
  for (; i > 0; i -= i & (-i))
    res += bit[i];
  return res;
}

int get(int l, int r) { return get(r) - get(l - 1); }

int bit_search(int v) {
  int sum = 0;
  int pos = 0;
  for (int i = LOGN; i >= 0; --i) {
    if (pos + (1 << i) < N && sum + bit[pos + (1 << i)] < v) {
      pos += 1 << i;
      sum += bit[pos];
    }
  }
  return pos + 1;
  // +1 because 'pos' will have position of largest value less than 'v'
}

int getMid(int L, int R) {
  int ans = R - L + 1;
  return (ans + 1) / 2;
}

int solve() {
  cin >> n >> q;
  block = LOGN;
  vi a(n);
  FOR(n) cin >> a[i];
  vt<query> qr(q);
  FOR(q) {
    cin >> qr[i].L >> qr[i].R;
    qr[i].L--;
    qr[i].R--;
    qr[i].pos = i;
  }
  sort(all(qr), cmp);
  vi ans(q);
  int currL = 0, currR = -1;
  FOR(q) {
    int L = qr[i].L, R = qr[i].R;
    while (currL > L) {
      currL--;
      update(a[currL], 1);
    }

    while (currR < R) {
      currR++;
      update(a[currR], 1);
    }
    while (currL < L) {
      update(a[currL], -1);
      currL++;
    }

    while (currR > R) {
      update(a[currR], -1);
      currR--;
    }
    // print(st);
    int mid = getMid(L, R);
    int med = bit_search(mid);
    ans[qr[i].pos] = med;
  }
  EACH(it, ans) cout << it << "\n";

  return 0;
}
int main() {
  IOS;
#ifndef ONLINE_JUDGE
  freopen("in1", "r", stdin);
  freopen("out2", "w", stdout);
#else
  // online submission
#endif

  solve();
  return 0;
}
