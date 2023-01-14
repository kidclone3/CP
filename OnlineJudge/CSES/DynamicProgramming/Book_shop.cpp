// https://cses.fi/problemset/task/1158
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
        cout << it.first << " " << it.second << "\n";
    }
    cout << "\n";
};
const int X = 1e5 + 5;
const int N = 1e3 +5;
int dp[X][N];
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    int mn = INT_MAX;
    FOR(n) {
        cin >> h[i];
        mn = min(mn, h[i]);
    } 
    vector<pair<int, int>> tmp(n);
    FOR(n) {
        cin >> s[i];
        tmp[i] = {h[i], s[i]};
    }
    sort(all(tmp));
    FOR(n) {
        tie(h[i], s[i]) = tmp[i];
    }
    for (int i = mn; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - h[j] >= 0) {
                if (dp[i-h[j]][n] + s[j] > dp[i][n] && dp[i-h[j]][j] == 0) {
                    dp[i][j] = 1;
                    dp[i-h[j]][j] = 1;
                    dp[i][n] = dp[i-h[j]][n] + s[j];
                    // cout << j << " " << dp[i][n] << "\n";
                }
            }
        }
    }
    int mx = 0;
    for(int i = x; i >= 1; --i) {
        mx = max(mx, dp[i][n]);
    }
    cout << mx;
}
