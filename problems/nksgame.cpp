#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n ; ++i) cin >> a[i];
    for(int i = 0; i < n ; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int l = 0, r = n-1;

    int ans = INT_MAX;
    while(l <= r) {
        ans = min(ans, abs(a[l]+b[r]));
        if (r - 1 >= l && abs(a[l]+b[r]) >= abs(a[l] + b[r-1])) {
            ans = min(ans, abs(a[l] + b[r]));
            r--;
        }
        else {
                ans = min(ans, abs(a[l]+b[r]));
                l++;
            }

    }
    l = 0, r = n-1;
    while(l <= r) {
        ans = min(ans, abs(b[l]+a[r]));
        if (r - 1 >= l && abs(b[l]+a[r]) >= abs(b[l] + a[r-1])) {
            ans = min(ans, abs(b[l] + a[r]));
            r--;
        }
        else {
                ans = min(ans, abs(b[l]+a[r]));
                l++;
            }

    }
    cout << ans;
    return 0;
}

int main() {
    solve();
}
