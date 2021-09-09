#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
const int N = 1e5+5;
const int M = 100+5;
const ll mod = 1e9+7;
ll dp[N][M];
void solve(){
    int n, m; cin >> n >> m;
    vl a(n);
    FOR(n) cin >> a[i];
    FOR(i, 1, n) {
        if (a[i] && a[i-1] && abs(a[i]-a[i-1]) > 1) {
            cout << 0;
            return;
        }
    }
    if (a[0] == 0) {
            FOR(j, 1, m+1) dp[0][j] = 1LL;
    }
    else dp[0][a[0]] = 1LL;
    FOR(i, 1, n) {
        if (a[i] == 0) {
            FOR(j, 1, m+1) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
                // else dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % mod;
            }
        }
        else {
            dp[i][a[i]] = (dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1]) % mod;
        }
    }
    // FOR(i, 0, n) FOR(j, 0, m+1) cout << dp[i][j] << " \n"[j==m];

    ll ans = 0LL;
    FOR(j, 0, m+1) ans = (ans + dp[n-1][j]) % mod;
    cout << ans;
}

int main()
{
    IOS;
    solve();
}