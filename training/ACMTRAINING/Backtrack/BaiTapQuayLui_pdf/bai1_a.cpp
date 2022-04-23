#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> s, ans;
bitset<100> mark;
void backtrack(int i) {
    if (i == k) {
        for(int j = 0; j < k; ++j) cout << ans[j] << " \n"[j==k-1];
        return;
    }
    for(int j = 1; j <= n; ++j) {
        if (mark[j]) continue;
        mark[j] = 1;
        ans.push_back(j);
        backtrack(i+1);
        mark[j] = 0;
        ans.pop_back();
    }
}

int main() {
    cin >> n >> k;
    backtrack(0);
}
