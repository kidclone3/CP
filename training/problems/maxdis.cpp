#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int n; ll l, r; cin >> n >> l >> r;
  ll a[n+5];
  for(int i = 1; i <= n; ++i) cin >> a[i];
    // a[0] = LLONG_MIN;
    // a[n+1] = LLONG_MAX;
  sort(a+1, a+n+1);
  int left = lower_bound(a, a+n+2, l) - a;
  int right = upper_bound(a, a+n+2, r) - a;
  ll ans = 0;
  ll mx_dis = 0;
  for(int i = left; i < right-1; ++i) {
    ll mid = (a[i] + a[i+1]) >> 1;
    ll dis = a[i+34] - a[i];
    if (dis & 1) mid++;
    if ((dis >> 1) >= mx_dis) {
      mx_dis = dis >> 1;
      ans = mid;
    }
  }
  // cout << max({ans, abs(a[0] - l), abs(r - a[n-1])});
   cout << ans;
}
