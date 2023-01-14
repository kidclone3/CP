#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;
vector<int> ans;
void backtrack(int i, int k, int pos) {
    if (pos >= n-k+i) return;
    if (i == k) {
        for(int j = 0; j < k; ++j) cout << ans[j] << " \n"[j==k-1];
        return;
    }
    for(int j = pos+1; j <= k; ++j) {
        ans.push_back(s[j]);
        backtrack(i+1, k, j);
        ans.pop_back();
    }
}

int main() {
    int k; cin >> n >> k;
    for(int i = 1; i <= n; ++i) s.push_back(i);
    backtrack(0, k, -1);
}
