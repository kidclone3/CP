// Suffix Array {{{
// Source: http://codeforces.com/contest/452/submission/7269543
// Efficient Suffix Array O(N*logN)

// String index from 0
// Usage:
// string s;  (s[i] > 0)
// SuffixArray sa(s);
// Now we can use sa.SA and sa.LCP
// sa.LCP[i] = max common prefix suffix of sa.SA[i-1] and sa.SA[i]
//
// Notes:
// - Number of distinct substrings = |S| * (|S| + 1) / 2 - sum(LCP)
//
// Tested:
// - (build SA) https://judge.yosupo.jp/problem/suffixarray
// - (LCP) https://judge.yosupo.jp/problem/number_of_substrings
// - (LCP - kth distinct substr) https://cses.fi/problemset/task/2108
// - (LCP - longest repeated substr) https://cses.fi/problemset/task/2106/
#include <algorithm>
// #include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct SuffixArray {
  string a;
  int N, m;
  vector<int> SA, LCP, x, y, w, c;

  SuffixArray(string _a, int _m = 256)
      : a(" " + _a), N(a.length()), m(_m), SA(N), LCP(N), x(N), y(N),
        w(max(m, N)), c(N) {
    a[0] = 0;
    DA();
    kasaiLCP();
#define REF(X)                                                                 \
  {                                                                            \
    rotate(begin(X), begin(X) + 1, end(X));                                    \
    X.pop_back();                                                              \
  }
    REF(SA);
    REF(LCP);
    a = a.substr(1, a.size());
    for (int i = 0; i < (int)SA.size(); ++i)
      --SA[i];
#undef REF
  }

  inline bool cmp(const int u, const int v, const int l) {
    return (y[u] == y[v] &&
            (u + l < N && v + l < N ? y[u + l] == y[v + l] : false));
  }

  void Sort() {
    for (int i = 0; i < m; ++i)
      w[i] = 0;
    for (int i = 0; i < N; ++i)
      ++w[x[y[i]]];
    for (int i = 0; i < m - 1; ++i)
      w[i + 1] += w[i];
    for (int i = N - 1; i >= 0; --i)
      SA[--w[x[y[i]]]] = y[i];
  }
  void DA() {
    for (int i = 0; i < N; ++i)
      x[i] = a[i], y[i] = i;
    Sort();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
      for (p = 0, i = N - j; i < N; ++i)
        y[p++] = i;
      for (int k = 0; k < N; ++k)
        if (SA[k] >= j)
          y[p++] = SA[k] - j;
      Sort();
      for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
        x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
  }
  void kasaiLCP() {
    for (int i = 0; i < N; ++i)
      c[SA[i]] = i;
    for (int i = 0, j, k = 0; i < N; LCP[c[i++]] = k)
      if (c[i] > 0)
        for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++)
          ;
      else
        k = 0;
  }
};

// Example:
// given string S and Q queries pat_i, for each query, count how many
// times pat_i appears in S
// O(min(|S|, |pat|) * log(|S|)) per query
//
// Tested:
// - (yes / no) https://cses.fi/problemset/task/2102
// - (count) https://cses.fi/problemset/task/2103
// - (position; need RMQ) https://cses.fi/problemset/task/2104
int count_occurrence(const string &s, const vector<int> &sa,
                     const string &pat) {
  int n = s.size(), m = pat.size();
  // assert(n == (int)sa.size());
  if (n < m)
    return 0;
  auto f = [&](int start) { // compare s[start:...] and pat[0: ...]
    for (int i = 0; start + i < n && i < m; ++i) {
      if (s[start + i] < pat[i])
        return true;
      if (s[start + i] > pat[i])
        return false;
    }
    return n - start < m;
  };
  auto g = [&](int start) {
    for (int i = 0; start + i < n && i < m; ++i) {
      if (s[start + i] > pat[i])
        return false;
    }
    return true;
  };
  auto l = std::partition_point(begin(sa), end(sa), f);
  auto r = std::partition_point(l, end(sa), g);
  cerr << "\t" << *l << " " << *r << "\n";
  return std::distance(l, r) == 0 ? -1 : *l + 1;
}

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<string> patterns;
  for (int i = 0; i < k; ++i) {
    string x;
    cin >> x;
    patterns.push_back(x);
  }
  SuffixArray sfa(s);
  for (int i = 0; i < k; ++i) {
    int ans = count_occurrence(s, sfa.SA, patterns[i]);
    cout << ans << '\n';
  }
}
