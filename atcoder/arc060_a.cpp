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

const int maxn = 60;
ll dp[maxn][maxn][maxn * maxn];

void solve(){
    int n, a;
    cin >> n >> a;
    vi x(n+1);
    FOR1(n) {
        cin >> x[i];
        // X = max(X, x[i]);
    }
    // print(x);
    // dp[i][j][s] = số cách chọn j phần tử từ 1 đến i sao cho tổng của chúng = s.
    dp[0][0][0] = dp[1][0][0] = 1LL;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int s = 2500; s >= 0; --s) {
                dp[i][j][s] = dp[i-1][j][s];
                if (j && s >= x[i]) dp[i][j][s] += dp[i-1][j-1][s-x[i]];
                // cout << dp[i][j][s] << " ";
            }
        }
    }
    ll ans = 0LL;
    // cout << dp[3][1][8] <<"\n";
    FOR(k, 1, n+1) {
        // cout << dp[n][k][k*a] << "\n";
        ans += dp[n][k][k*a];
    }
    cout << ans << "\n";
}

int main()
{
    IOS;
    solve();
}