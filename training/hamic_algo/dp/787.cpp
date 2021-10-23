#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void solve() {
    int n = a.size();
    pair<int, int> dp[n];
    int ans = -1e9;
    for(int i = 0; i < n; ++i) {
        if (!i) dp[i].first = dp[i].second = a[i];
        else {
            if (a[i] >= 0) {
                dp[i].first = max(a[i], a[i]*dp[i-1].first);
                dp[i].second = min(a[i], a[i]*dp[i-1].second);
            } else {
                dp[i].first = max(a[i], a[i]*dp[i-1].second);
                dp[i].second = min(a[i], a[i]*dp[i-1].first);
            }
        }
        ans = max(ans, dp[i].first);
    }
    cout << ans << "\n";
}

int main() {
    int tmp;
    while(cin >> tmp) {
        if (tmp != -999999) {
            a.push_back(tmp);
        } else {
            solve();
            a.clear();
        }
    }
}