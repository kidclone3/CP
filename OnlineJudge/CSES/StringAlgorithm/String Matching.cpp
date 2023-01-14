#include <bits/stdc++.h>
using namespace std;

int solve() {
  string txt;
  cin >> txt;
  string pat;
  cin >> pat;
  int n = txt.size();
  int m = pat.size();
  vector<int> lps(m + 5, 0);
  // Preprocessing
  for (int i = 1; i < m; ++i) {
    int j = lps[i - 1];
    while (j > 0 && pat[i] != pat[j])
      j = lps[j - 1];
    if (pat[i] == pat[j])
      j++;
    lps[i] = j;
  }

  // KMP
  int i, j;
  i = j = 0;
  int ans = 0;
  while ((n - i) >= (m - j)) {
    if (txt[i] == pat[j]) {
      i++, j++;
    }
    if (j == m) {
      ans++;
      j = lps[j - 1];
    } else if (i < n && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
    // cout << "-";
  }
  cout << ans;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
