#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, r; cin >> n >> r;

    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    int range = 0;
    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if (a[i] == a[i-1]) continue;
        if (-range + a[i] <= 0) break;
        ans++;
        range += r;
    }
    cout << ans << '\n';
}

int main() {
    int t; cin>> t;
    while(t--) solve();
}