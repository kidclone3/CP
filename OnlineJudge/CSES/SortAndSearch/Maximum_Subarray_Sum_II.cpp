#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main() {
    int n; cin >> n;
    int mn, mx; cin >> mn >> mx;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> s(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        s[i] = s[i-1] + a[i-1];
    }
    queue<ll> q;
    multiset<ll> zone;
    ll ans = LLONG_MIN;
    for(int i = 1; i <= n; ++i) {
        q.push(s[i-1]);
        if (q.size() >= mn) zone.insert(q.front()), q.pop();
        if (!zone.empty()) {
            ans = max(ans, s[i] - *zone.begin());
        }
        if (i >= mx) zone.erase(zone.find(s[i-mx]));
    }
    cout << ans;
}