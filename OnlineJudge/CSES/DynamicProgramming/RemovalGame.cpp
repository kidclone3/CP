#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &it: a) cin >> it;
    auto dfs = [&] (int l, int r) {
        vector<ll> trace;
        while (l <= r) {
            if (a[l] > a[r]) trace.push_back(a[l++]);
            else trace.push_back(a[r--]);
        }
        return trace;
    };
    vector<ll> trace1, trace2;
    trace1 = dfs(1, n-1); trace1.insert(trace1.begin(), a[0]);
    trace2 = dfs(0, n-2); trace2.insert(trace2.begin(),a[n-1]);

    ll sum1, sum2; sum1 = sum2 = 0LL;
    // for(auto &it: trace1) cout << it << " "; cout << '\n';
    // for(auto &it: trace2) cout << it << " "; cout << '\n';
    for(int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sum1 += trace1[i];
            sum2 += trace2[i];
        }
    }
    cout << max(sum1, sum2);
}