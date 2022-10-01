#include <bits/stdc++.h>
using namespace std;

int solve() {
  // Manacher algorithm
  string s;
  cin >> s;
  string ss = "";
  for (auto &ch : s) {
    ss.push_back('#');
    ss.push_back(ch);
  }
  ss.push_back('#');
  int n = ss.size();
  ss = "$" + ss + "^";
  vector<int> p(n + 2, 0);

  int l = 1, r = 1;

  for (int i = 1; i <= n; ++i) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (ss[i - p[i]] == ss[i + p[i]])
      p[i]++;
    if (i + p[i] > r) {
      l = i - p[i];
      r = i + p[i];
    }
  }
  // for(auto &it: p) cerr << it << " ";
  // cerr <<'\n';
  int mx = -1, idx = -1;
  for (int i = 1; i <= n; ++i)
    if (p[i] > mx)
      mx = p[i], idx = i;
  // cerr << mx <<" " << idx << '\n';
  string tmp = ss.substr(idx - mx + 1, 2 * mx - 1);
  // cout << ss << '\n';
  // cout << tmp << '\n';
  for (auto &it : tmp)
    if (it != '#')
      cout << it;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
