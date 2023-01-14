#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve() {
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    if (n == 1) return cout << "0\n", 0;
    sort(begin(x), end(x));
    sort(begin(y), end(y));
    ll ans = 0LL;
    for(int i = 0; i < n; ++i) {
        ans += (i - (n-i-1)) * (x[i] + y[i]);
    }
    cout << ans << '\n';
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}

