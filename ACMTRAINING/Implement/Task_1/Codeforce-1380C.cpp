#include<bits/stdc++.h>
using namespace std;
int solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    int curr = 1;
    for(int i = 0; i < n; ++i) {
        if (a[i] >= x) ans++;
        else {
            if (a[i]*curr >= x) {
                ans++;
                curr = 1;
            } else curr++;
        }
    }
    cout << ans << "\n";
    return 0;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
        
}
