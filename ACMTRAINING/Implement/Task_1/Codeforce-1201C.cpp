#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    // int med = a[n/2];
    ll sum = 0LL; 
    ll ans = -1;
    bool isOk = true;
    for(int i = n/2+1; i < n; ++i) {
        ll add = (i-n/2)*(a[i]-a[i-1]);
        if (sum + add <= k) {
            sum += add;
        } else {
            k -= sum;
            ll add2 = k/(i-n/2);
            ans = a[i-1] + min(a[i]-a[i-1], add2);
            isOk = false;
            break;
        }
    }
    if (!isOk) {
        cout << ans;
    } else {
        k -= sum;
        // cout << k << " " << sum << "\n";
        ans = a[n-1];
        ans += k/(n/2+1);
        cout << ans;
    }
}
