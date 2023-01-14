#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_tree;

int solve() {
  int n, q;
  cin >> n >> q;
  ordered_tree st;
  for (int i = 0; i < n; ++i) {
    st.insert(i + 1);:
  }
  int curr = 0;
  while (!st.empty()) {
    // for(auto &it: st) cerr << it << " ";
    // cerr << '\n';
    curr = (curr + k) % st.size();
    auto tmp = st.find_by_order(curr);
    cout << *tmp << " ";
    st.erase(tmp);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
