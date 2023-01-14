// LS = linear search = bruteforce
// Wrong on even palindrome, and TLE (ofc)
#include<bits/stdc++.h>
using namespace std;

int solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> dp(n+5, 0);
    int mx = -1, idx = -1;
    for(int i = 1; i < n-1; ++i) {
        int l = 0;
        while (i - l >= 0 && i + l <= n-1 && s[i-l] == s[i+l]) l++;
        dp[i] = l;
        if (dp[i] > mx) {
            mx = dp[i];
            idx = i;
        }
    }
    // for(auto &it : dp) cout << it << " ";
    string ans = s.substr(idx-mx+1, 2*mx -1);
    cout << ans;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

