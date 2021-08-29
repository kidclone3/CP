// https://codeforces.com/problemset/problem/1369/C
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), w(k);
    FOR(i, n) {
        cin >> a[i];
    }
    FOR(i, k) {
        cin >> w[i];
    }
    sort(all(a));
    reverse(all(a));
    print(a);
    sort(all(w));
    ll ans = 0;
    for (int start = 0, i = n-1, j = 0; j < k; start++, j++) {
        if (w[j] == 1) {
            ans += 2 * a[start];
        }
        else {
            ans += a[start] + a[i];
            i -= w[j] - 1;
        }
    }
    cout << ans << "\n";
}
