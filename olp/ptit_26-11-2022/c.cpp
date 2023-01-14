#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve() {
    int n; cin >> n;
    multiset<ll> st;
    vector<ll> a(n);
    ll sum = 0LL;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
        sum += a[i];
    }
    double mx = -1.0;
    vector<int> pos;
    for(int i = 0; i < n-1; ++i) {
        st.erase(st.lower_bound(a[i]));
        sum -= a[i];
        double tmp = 1.0*(sum - *st.begin())/(n-i-2);
        // cerr << tmp << '\n';
        if (tmp > mx) {
            mx = tmp;
            pos.clear();
            pos.push_back(i);
        } else if (abs(tmp - mx) < 1e-6) {
            pos.push_back(i);
        }
    }
    for(auto &it: pos) cout << it+1 << " ";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}