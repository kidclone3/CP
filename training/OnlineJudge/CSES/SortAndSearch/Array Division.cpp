#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    
    ll l = 0LL, r = 1e18;
    for(int i = 0; i < n; ++i) cin >> a[i], l = max(l, a[i]);
    ll ans = -1;
    auto check = [&](ll mid) {
        int cnt = 0;
        ll sum = 0LL;
        for(int i = 0; i < n; ++i) {
            if (sum + a[i] > mid) cnt++, sum = 0LL;
            sum += a[i];
        }
        if (sum > 0) cnt++;
        return cnt <= k;
    };
    while (l <= r) {
        ll mid = (l+r)>>1LL;
        cerr << mid << " " << check(mid) << '\n';
        if (check(mid)) {
            ans = mid;
            r = mid - 1LL;
        } else l = mid + 1LL;
    }
    cout << ans;
}
