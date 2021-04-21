#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+2), dp(n+2, 0), ans(n);
    ll sum = 0;
    set<ll> mx;
    map<ll, int> mp;
    F_OR(i, 0, n+2, 1) {
        cin >> a[i];
        // mx = max(mx, a[i]);
        mx.insert(a[i]);
        mp[a[i]]++;
        sum += a[i];
    }
    ll x = 0;
    ll mx_val= 0;
    F_OR(i, 0, n+2, 1) {
        auto it = mx.lower_bound((sum - a[i])/2);
        if (sum - a[i] - *it == *it && ((a[i] != *it) || (a[i] == *it && mp[*it]>1))) {
            dp[i] = 2;
            x = a[i];
            mx_val = *it;
            break;
        }
    }
    F_OR(i, 0, n+2, 1) {
        if (a[i] == mx_val && !dp[i]) {
            dp[i] = 1;
            break;
        }
    }
    if (x==0) {
        cout<<"-1\n";
        return;
    }
    int j = 0;
    F_OR(i, 0, n+2, 1) {
        if (!dp[i]) {
            ans[j++] = a[i];
        }
    }
    print(ans);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input3.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
