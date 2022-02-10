// https://codeforces.com/contest/698/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, n) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector(3, (int) 1e9)) ;
    dp[0][0] = 1;
    if (a[0] == 3) {
        dp[0][1] = dp[0][2] = 0;
    }
    else if (a[0] == 0){
        
    }
    else {
        dp[0][a[0]] = 0;
    }
    for (int i = 1 ; i < n; ++i) {
        dp[i][0] = 1 + min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if (a[i] == 0) {
            dp[i][0] = dp[i][1] = dp[i][2] = 1 + min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }
        if (a[i] == 1) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
        if (a[i] == 2) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
        if (a[i] == 3) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
