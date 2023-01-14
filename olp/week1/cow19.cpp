#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    int n;
    ll a, b;
    cin >> n >>  a >> b;
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; ++i) {
        ll x, y, r;
        cin >> x >> y >> r;
        double dis = sqrt((x-a) * (x-a) * 1.0 + (y-b)*(y-b) * 1.0);
        // if (r > 0) r += 1;
        double low_dis = floor(dis - r);
        if (low_dis == dis - r) low_dis--;
        if (low_dis >= 0) {
            ans = min(ans, (ll) low_dis);
        } else ans = 0;
    }
    cout << ans;
}