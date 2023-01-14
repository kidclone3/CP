#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> vt;
    for (int i = 0; i < (1<<n); ++i) {
        string s(n, '0');
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) s[j] = '1';
        }
        vt.push_back(s);
    }
    sort(vt.begin(), vt.end());
    for(auto it:vt) {
        cout << it << " ";
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}