#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
    long long t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> vt;
    for(long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        vt.push_back({tmp, i});
    }
    // for(long long i = 0; i< n; i++) {
    //     cout<<vt[i].first <<" " << vt[i].second <<'\n';
    // }
    sort(vt.begin(), vt.end());
    vector<pair<long long, long long>> b;
    long long dp[n];
    dp[0] = vt[0].first;
    b.push_back({dp[0]-vt[1].first, vt[0].second});
    
    for(long long i = 1; i < n-1; i++) {
        dp[i] = dp[i-1] + vt[i].first;
        b.push_back({dp[i] - vt[i+1].first, vt[i].second});
    }
    vector<long long> ans;
    ans.push_back(vt[n-1].second);
    for (long long i = n-2; i >= 0; i--) {
        if(b[i].first >= 0) {
            ans.push_back(b[i].second);
        }
        else {
            break;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() <<'\n';
    for(long long i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    // for(long long i = 0; i< n-1; i++) {
    //     cout<<b[i].first <<" " << b[i].second <<'\n';
    // }
}