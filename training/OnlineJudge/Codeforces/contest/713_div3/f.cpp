#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n+1), b(n);
    FOR1(i, n) {
        cin >> a[i];
    } 
    FOR1(i, n-1) {
        cin >> b[i];
    }
    ll dp[n+1][5];
    // dp[i][1] = budget
    // dp[i][2] = min days to buy
    // dp[i][3] = time to reach this salary.
    int i = 1;
    dp[1][1] = a[1];
    dp[1][2] = (c - 1) / a[1] + 1;
    dp[1][3] = 1;
    ll ans = dp[1][2];
    F_OR(i, 2, n+1, 1) {
        ll budget = dp[i-1][1];
        ll timeReach;
        if (budget - b[i-1] >= 0) {
            timeReach = 1;
            budget -= b[i-1];
        }
        else {
            timeReach = (b[i-1] - budget - 1) / a[i-1] + 2;
            budget = budget + a[i-1] * (timeReach - 1) - b[i-1];
        }
        ll timeBuyComp = (c - budget - 1) / a[i] + 1;
        dp[i][1] = budget;
        dp[i][3] = dp[i-1][3] + timeReach;
        dp[i][2] = dp[i][3] + timeBuyComp;
        ans = min(ans, dp[i][2]);
    }
    cout << ans <<'\n';
}