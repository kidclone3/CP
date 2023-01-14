#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll sq(ll x) { return x * x; }
ll optimize(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    // we use this lemma:
    // a_x <= b_y <= c_z; so the answer is optimize;
    // now we fix the y value and use l_b to find x and z value;
    ll ans = LLONG_MAX;
    for(int y = 0; y < (int) b.size(); ++y) {
        auto aa = lower_bound(a.begin(), a.end(), b[y]);
        auto cc = upper_bound(c.begin(), c.end(), b[y]);
        if (aa == a.end() || cc == c.begin()) continue;
        cc--;
        ll tmp = sq(b[y] - *aa) + sq(b[y] - *cc) + sq (*cc - * aa);
        ans = min(ans, tmp);
    }
    return ans;
}

void solve() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    vector<ll> a(n1), b(n2), c(n3);
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n3; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    
    ll l[6];
    l[0] = optimize(a, b, c);
    l[1] = optimize(a, c, b);
    l[2] = optimize(b, c, a);
    l[3] = optimize(b, a, c);
    l[4] = optimize(c, a, b);
    l[5] = optimize(c, b, a);
    ll ans = *min_element(l, l+ 6);
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}