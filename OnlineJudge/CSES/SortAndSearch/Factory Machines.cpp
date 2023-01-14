#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll l = 1LL, r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l+r)>>1LL;
        ll sum = 0LL;
        for(auto &it : a) {
            sum += mid / it;
            if (sum >= t) break;
        }
        if (sum >= t) {
            ans = mid;
            r = mid - 1;
            // cerr << ans << " " << sum << '\n';
        } else l = mid + 1;
    }
    cout << ans;
}
