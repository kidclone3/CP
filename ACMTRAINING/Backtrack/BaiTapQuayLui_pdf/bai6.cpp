#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void backtrack(int x, int k) {
    if (x == 0) {
        for(auto it : ans) cout << it << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= min(k, x); ++i) {
        ans.push_back(i);
        backtrack(x-i, k);
        ans.pop_back();
    }
}

int main() {
    int n, k; cin >> n >> k;
    backtrack(n, k);
}
