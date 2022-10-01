#include<bits/stdc++.h>

using namespace std;

int solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> a;
    vector<int> prices(m);
    for(int i = 0; i < m; ++i) {
        int k; cin >> k;
        vector<int> stickers(k);
        for(int j = 0; j < k; ++j) {
            cin >> stickers[j];
        }
        a.push_back(stickers);
        int price; cin >> price;
        prices[i] = price;
    }
    vector<int> collections(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> collections[i];
    }
    // for(auto &it : collections) cerr << it << " ";
    // cerr <<'\n';
    // for(auto &it : prices) cerr << it << " ";
    // cerr <<'\n';
    long long ans = 0LL;
    for(int i = 0; i < m; ++i) {
        int pp = INT_MAX;
        for(auto &it : a[i]) {
            pp = min(pp, collections[it]);
        }
        // cerr << pp << '\n';
        ans += pp * prices[i];
    }
    cout << ans << '\n';
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
