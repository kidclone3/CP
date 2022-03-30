#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    // Bai toan dem, dung map.
    map<int, int> mp;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            mp[x]++;
        }
    }
    vector<int> tmp;
    for(auto &it : mp) {
        tmp.push_back(it.second);
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    int ans = 0;
    for(auto &it : tmp) cout << it << " ";
    for(int i = 0; i < k; ++i) {
        ans += tmp[i];
    }
    cout << ans;
}
