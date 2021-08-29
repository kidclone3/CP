// https://codeforces.com/gym/302977/problem/D
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
    solve();
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    vector<ll> dp(n+1), mx(n+1, 0);
    vector<ll> dp_back(n+1, 0), dp_front(n+1, 0);
    dp_front[0] = dp[0] = 0;
    FOR1(n) {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    } 
    FOR1(n) {
        cin >> b[i];
    } 
    dp_back[n] = a[n] * b[n];
    FOR1(n) {
        dp_front[i] = a[i] * b[i] + dp_front[i-1];
    }
    FOR(i, n-1, 0, -1) {
        dp_back[i] = a[i] * b[i] + dp_back[i+1];
    }
    // ll sum = 0LL; // to calculate 
    // the theorems can be written 
    // without using technique
    ll ans = 0LL;
    FOR(i, 1, n - k + 2) {
        mx[i] = dp_front[i-1] + dp[i+k-1] - dp[i-1];
        if (i != n - k + 1) mx[i] += dp_back[i+k];
        ans = max(ans, mx[i]);
    }
    // print(mx);
    cout << ans;
}
